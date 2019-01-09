#include "temp_sensor_test.h"
#include "logger.hpp"
#include "sensor.h"
#include "cap_nwl_sbus_api.h"
#include "cap_sbus_api.h"

#define TEMP_SENSOR_COMMON_TESTS_OPTION    \
    {"all", no_argument, NULL, 'a'}, /* Run all the tests */ \
    {"help", no_argument, NULL, 'h'}, /* Show usage */ \
    {"local", no_argument, NULL, 'l'}, /* test for asic*/ \
    {"die", no_argument, NULL, 'd'}, /* test for die*/ \
    {"hbm", no_argument, NULL, 'm'}, /* test for hbm*/ \


struct option temp_sensor_online_diag_options[] =
{
    TEMP_SENSOR_COMMON_TESTS_OPTION
    /* Add online diags specific options here  */
    {0, 0, NULL, 0}
};

struct option temp_sensor_offline_diag_options[] =
{
    TEMP_SENSOR_COMMON_TESTS_OPTION
    /* Add offline diags specific options here  */
    {0, 0, NULL, 0}
};

struct option temp_sensor_post_options[] =
{
    TEMP_SENSOR_COMMON_TESTS_OPTION
    /* Add post specific options here  */
    {0, 0, NULL, 0}
};


void temp_sensor_common_tests_usage()
{
    printf (
"-all           Run all the temp sensor test in given mode\n"
"-local         Run temp sensor test for ASIC\n"
"-die           Run temp sensor test for Die\n"
"-hbm           Run HBM temp test\n"
"-help          Show this usage summary\n"
);

}

void temp_sensor_online_diag_usage()
{
    /* Add online diag specific usage here  */
    //As of now nothing
}

void temp_sensor_offline_diag_usage()
{
    /* Add offline diag specific usage here  */
    //As of now nothing
}

void temp_sensor_post_usage()
{
    /* Add post specific usage here  */
    //As of now nothing
}

void temp_sensor_test_usage(test_mode_e mode)
{
    temp_sensor_common_tests_usage();

    if (mode == ONLINE_DIAG)
        temp_sensor_online_diag_usage();
    else if (mode == OFFLINE_DIAG)
        temp_sensor_offline_diag_usage();
    else if (mode == POST)
        temp_sensor_post_usage();

    return;
}

#define MIN_LOCAL_TEMPERATURE_SUPPORTED      (1)
#define MAX_LOCAL_TEMPERATURE_SUPPORTED      (85)

#define MIN_DIE_TEMPERATURE_SUPPORTED      (1)
#define MAX_DIE_TEMPERATURE_SUPPORTED      (105)

#define MIN_HBM_TEMPERATURE_SUPPORTED      (1)
#define MAX_HBM_TEMPERATURE_SUPPORTED      (105)


int local_temp_sensor_test()
{
    uint64_t local_temperature = 0;
    int retval = 0;

    retval = read_local_temperature(&local_temperature);

    if (retval)
    {
        SDK_TRACE_ERR("Cannnot read Local temperature sensor data\n");
    }
    else
    {
        //convert to degree celsius
        local_temperature = local_temperature/1000;

        SDK_TRACE_INFO("Local temperature is (%d) degree Celsius \n", local_temperature);

        if (local_temperature > MAX_LOCAL_TEMPERATURE_SUPPORTED)
        {
            SDK_TRACE_ERR("Local temperature(%d) is above Max limit(%d)\n", local_temperature,  MAX_LOCAL_TEMPERATURE_SUPPORTED);
            retval = -1;
        }

        if (local_temperature < MIN_LOCAL_TEMPERATURE_SUPPORTED)
        {
            SDK_TRACE_ERR("Local temperature(%d) is below Min limit(%d)\n", local_temperature,  MIN_LOCAL_TEMPERATURE_SUPPORTED);
            retval = -1;
        }
    }

    LOG_TEST_RESULT("Local Temperature Sensor Test", retval);

    return retval;
}

int die_temp_sensor_test()
{
    float die_temperature = 0;
    int retval = 0;

    die_temperature = cap_get_temp();
    SDK_TRACE_INFO("Die temperature is (%f) degree Celsius\n", die_temperature);

    if (die_temperature > MAX_DIE_TEMPERATURE_SUPPORTED)
    {
        SDK_TRACE_ERR("Die temperature(%f) is above Max limit(%d)\n", die_temperature,  MAX_DIE_TEMPERATURE_SUPPORTED);
        retval = -1;
    }

    if (die_temperature < MIN_DIE_TEMPERATURE_SUPPORTED)
    {
        SDK_TRACE_ERR("Die temperature(%f) is below Min limit(%d)\n", die_temperature,  MIN_DIE_TEMPERATURE_SUPPORTED);
        retval = -1;
    }

    LOG_TEST_RESULT("Die Temperature Sensor Test", retval);

    return retval;
}

int hbm_temp_test()
{
    uint64_t hbm_temperature = 0;
    int retval = 0;

    hbm_temperature = cap_nwl_sbus_get_1500_temperature();

    SDK_TRACE_INFO("HBM temperature is (%d) degree Celsius \n", hbm_temperature);
    if (hbm_temperature > MAX_HBM_TEMPERATURE_SUPPORTED)
    {
        SDK_TRACE_ERR("HBM temperature(%d) is above Max limit(%d)\n", hbm_temperature,  MAX_HBM_TEMPERATURE_SUPPORTED);
        retval = -1;
    }

    if (hbm_temperature < MIN_HBM_TEMPERATURE_SUPPORTED)
    {
        SDK_TRACE_ERR("HBM temperature(%d) is below Min limit(%d)\n", hbm_temperature,  MIN_HBM_TEMPERATURE_SUPPORTED);
        retval = -1;
    }

    LOG_TEST_RESULT("HBM Temperature Sensor Test", retval);

    return retval;
}

diag_ret_e temp_sensor_test(test_mode_e mode, int argc, char* argv[])
{
    int arg_option;
    int index, retval;
    struct option* option;

    /** test flags */
    int test_all=0;
    int test_local_temp=0, test_die_temp=0, test_hbm_temp=0;


    if(mode == OFFLINE_DIAG)
        option = temp_sensor_offline_diag_options;
    else if(mode == ONLINE_DIAG)
        option = temp_sensor_online_diag_options;
    else if(mode == POST)
        option = temp_sensor_post_options;
    else
    {
        return TEST_INVALID_OPTION;
    }

    if (argc < 2)
        test_all = 1;

    while ((arg_option = getopt_long_only(argc, argv, "", option, &index)) >= 0) /* Parse command line args */
    {
        switch (arg_option)
        {
            case 'l':
                test_local_temp = 1;
                break;
            case 'd':
                test_die_temp = 1;
                break;
            case 'm':
                test_hbm_temp = 1;
                break;
            case 'h':
                temp_sensor_test_usage(mode);
                return TEST_SHOW_HELP;;
            case 'a':
                test_all = 1;
                break;
            case '?':
            default:
                printf("Invalid option provoided!\n");
                printf("Please run with -h to see usage:\n");
                return TEST_INVALID_OPTION;
        }
    }

   if (optind < argc) {
        printf("Ignoring non-option argv-elements: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }
 
   LOG_TEST_BANNER("Temperature Sensors Tests:");

   if (test_all)
   {
       test_local_temp = 1;
       test_die_temp = 1;
       test_hbm_temp = 1;
   }

   if (test_local_temp)
       retval = local_temp_sensor_test();

   if (test_die_temp)
       retval = die_temp_sensor_test();

   if (test_hbm_temp)
       retval = hbm_temp_test();

   return (retval ? TEST_PASS : TEST_FAIL);
}

