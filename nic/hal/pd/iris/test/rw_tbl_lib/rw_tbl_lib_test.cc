#include <gtest/gtest.h>
#include <rw_pd.hpp>
#include <hal_pd.hpp>
#include <eth.h>

using hal::pd::pd_rw_entry_key_t;
using hal::pd::pd_rw_entry_t;

class rw_test : public ::testing::Test {
protected:
    rw_test() {
  }

  virtual ~rw_test() {
  }

  // will be called immediately after the constructor before each test
  virtual void SetUp() {
  }

  // will be called immediately after each test before the destructor
  virtual void TearDown() {
  }

};

/* -----------------------------------------------------------------------------
 *
 * Test Case 1:
 *      - Test Case to verify the insert
 * - Create DM table
 * - Insert DM Entry
 *
 * ---------------------------------------------------------------------------*/
TEST_F(rw_test, test1) {
    hal_ret_t           ret;
    pd_rw_entry_key_t   key;
    pd_rw_entry_t       *rwe;
    uint64_t            mac_sa = 0x000000000001;
    uint64_t            mac_da = 0x000000000002;
    uint64_t            mac_da1 = 0x000000000003;
    uint32_t            rw_idx = 0, rw_idx1 = 0;

    MAC_UINT64_TO_ADDR(key.mac_sa, mac_sa);
    MAC_UINT64_TO_ADDR(key.mac_da, mac_da);
    key.rw_act = REWRITE_REWRITE_ID;

    ret = rw_entry_find(&key, &rwe);
    ASSERT_TRUE(ret == HAL_RET_ENTRY_NOT_FOUND);

    ret = rw_entry_alloc(&key, NULL, &rw_idx);
    ASSERT_TRUE(ret == HAL_RET_OK);

    ret = rw_entry_find_or_alloc(&key, &rw_idx1);
    ASSERT_TRUE(ret == HAL_RET_OK);

    ASSERT_TRUE(rw_idx == rw_idx1);

    MAC_UINT64_TO_ADDR(key.mac_da, mac_da1);
    ret = rw_entry_alloc(&key, NULL, &rw_idx);
    ASSERT_TRUE(ret == HAL_RET_OK);
    
    MAC_UINT64_TO_ADDR(key.mac_da, mac_da);
    ret = rw_entry_delete(&key);
    ASSERT_TRUE(ret == HAL_RET_OK);

    ret = rw_entry_delete(&key);
    ASSERT_TRUE(ret == HAL_RET_OK);

    ret = rw_entry_delete(&key);
    ASSERT_TRUE(ret == HAL_RET_ENTRY_NOT_FOUND);
}

#if 0
TEST_F(rw_test, test1) {

    output_mapping_actiondata dm;
    uint32_t index;
    dm.actionid = 1;

    hal_ret_t rt;
    rt = test_dm.insert(&dm, &index); 
    ASSERT_TRUE(rt == HAL_RET_OK);

}
#endif

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  hal::pd::hal_pd_mem_init();
  return RUN_ALL_TESTS();
}
