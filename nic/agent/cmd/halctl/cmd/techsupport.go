package cmd

import (
	"os"

	"github.com/spf13/cobra"

	"github.com/pensando/sw/venice/utils/log"
)

var tsShowCmd = &cobra.Command{
	Use:   "techsupport",
	Short: "collect technical support information",
	Long:  "collect technical support information",
	Run:   tsShowCmdHandler,
}

// default location of the output file
var (
	outDir  = "/tmp/hal_techsupport"
	outFile = "hal-cmds.txt"
)

func init() {
	showCmd.AddCommand(tsShowCmd)
	tsShowCmd.Flags().StringVar(&outDir, "out", outDir, "output directory")
}

func tsShowCmdHandler(cmd *cobra.Command, args []string) {
	outFile = outDir + "/" + outFile

	// remove the output directory if one exists
	err := os.RemoveAll(outFile)
	if err != nil {
		log.Errorf("Failed to remove directory %s, err : %v", outFile, err)
		os.Exit(1)
	}

	// create a new directory
	err = os.MkdirAll(outDir, 0777)
	if err != nil {
		log.Errorf("Failed to create directory %s, err : %v", outDir, err)
		os.Exit(1)
	}

	// create the o/p file
	ofile, err := os.OpenFile(outFile, os.O_CREATE|os.O_RDWR|os.O_APPEND, 0660)
	if err != nil {
		log.Errorf("Failed to create output file %s, err : %v", outFile, err)
		os.Exit(1)
	}

	ofile.WriteString("Capturing techsupport information\n\n")
	ofile.WriteString("Flush HAL logs\n\n")
	flushLogsDebugCmdHandler(nil, nil)
	ofile.WriteString("Lif information\n\n")
	handlelifDetailShowCmd(nil, ofile)
	ofile.WriteString("Interface information\n\n")
	handleIfDetailShowCmd(nil, ofile)
	ofile.WriteString("Security profile information\n\n")
	handleNwsecProfShowCmd(nil, ofile)
	ofile.WriteString("VRF information\n\n")
	handleVrfDetailShowCmd(nil, ofile)
	ofile.WriteString("L2 segment information\n\n")
	handlel2segDetailShowCmd(nil, ofile)
	ofile.WriteString("Network information\n\n")
	handleNwDetailShowCmd(nil, ofile)
	ofile.WriteString("Security policy information\n\n")
	handleNwsecPolicyShowCmd(nil, ofile)
	ofile.WriteString("Endpoint information\n\n")
	handleEpDetailShowCmd(nil, ofile)
	ofile.WriteString("Session information\n\n")
	handleSessionDetailShowCmd(nil, ofile)
	ofile.WriteString("ACL information\n\n")
	handleACLShowCmd(nil, ofile)
	ofile.WriteString("Memory information\n\n")
	allMemoryShowHandler(ofile)
	ofile.WriteString("Thread information\n\n")
	threadDetailShow(ofile)
	ofile.WriteString("System information\n\n")
	handleSystemDetailShowCmd(nil, ofile)
	ofile.WriteString("Flush HAL logs\n\n")
	flushLogsDebugCmdHandler(nil, nil)
	ofile.Close()
}
