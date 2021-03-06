#include "key_mgr.h"
#include "resource_manager.h"

#include "./ceil10a/key_ceil10a.h"
#include "./ceil10b/key_ceil10b.h"
#include "./ceil08/key_ceil8.h"
#include "./uarm10/key_uarm10.h"
#include "./uarm08/key_uarm8.h"
#include "./rail08/key_rail8.h"
#include "./rail12/key_rail12.h"

CKeyMgr::CKeyMgr()
{
    mTestBase = 0;
}

CKeyBase * CKeyMgr::keyInit(int mpf)
{
    switch(mpf)
    {
    case PF_CEIL_10_A:
        mTestBase    = new CKeyCeil10a();
        break;
    case PF_CEIL_10_B:
        mTestBase    = new CKeyCeil10b();
        break;
    case PF_CEIL_08_A:
        mTestBase    = new CKeyCeil8();
        break;
    case PF_UARM_10_A:
        mTestBase    = new CKeyUarm10();
        break;
    case PF_UARM_08_A:
        mTestBase    = new CKeyUarm8();
        break;
    case PF_RAIL_12_A:
        mTestBase    = new CKeyRail12();
        break;
    case PF_RAIL_08_A:
        mTestBase    = new CKeyRail8();
        break;
    default:
        mTestBase    = new CKeyCeil10a();
        break;
    }
    return mTestBase;
}
