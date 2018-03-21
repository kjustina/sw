#! /usr/bin/python3
import test.fte.alg.tracker.tracker as trackermod

def InitTracker(infra, module):
    tracker = trackermod.ALGTrackerObject()
    tracker.Init(module.name, module.args.connspec)
    return tracker

def Setup(infra, module):
   return

def Teardown(infra, module):
    return

def TestCaseSetup(tc):
    stepspec = tc.module.iterator.Get()
    tc.tracker.SetStep(stepspec, tc)
    tc.tracker.SetupTestcaseConfig(tc)
    return

def TestCaseVerify(tc):
    return True

def TestCaseTeardown(tc):
    if tc.tracker.IsFteDone():
        root = getattr(tc.tracker.config, 'flow', None)
        session = root.GetSession()
        session.SetLabel("FTE_DONE")

        #tc.tracker.pvtdata.fte_session_aware = False

    tc.tracker.Advance()
    return
