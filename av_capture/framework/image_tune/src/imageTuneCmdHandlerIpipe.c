#include <imageTunePriv.h>

int IMAGE_TUNE_CmdExecuteIpipeColPat(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeColPatConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.colPat;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal = CSL_ipipeSetColPatConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeLsc(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeLscConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.lsc;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal = CSL_ipipeSetLscConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeDpc(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeDpcConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.dpc;
    Uint32 *pTable = gIMAGE_TUNE_ctrl.curPrm.ipipePrm.dpcTable;
    Uint32 prmSize = sizeof(*pPrm);
    Uint32 tableSize = sizeof(gIMAGE_TUNE_ctrl.curPrm.ipipePrm.dpcTable);
    Uint32 reqdPrmSize = prmSize + tableSize;

    if (cmdInfo->prmSize != reqdPrmSize)
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm,    cmdInfo->prm, prmSize);
    memcpy(pTable,  (Uint8*)cmdInfo->prm + prmSize, tableSize);

    pPrm->lutAddr = pTable;

    retVal = CSL_ipipeSetDpcConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeNf1(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeNfConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.nf1;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal = CSL_ipipeSetNf1Config(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeNf2(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeNfConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.nf2;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal = CSL_ipipeSetNf2Config(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeGic(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeGicConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gic;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal = CSL_ipipeSetGicConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeWb(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeWbConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.wb;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal = CSL_ipipeSetWbConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeCfa(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeCfaConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.cfa;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal = CSL_ipipeSetCfaConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeRgb2Rgb1(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeRgb2RgbConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2rgb1;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal = CSL_ipipeSetRgb2Rgb1Config(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeGamma(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    Uint32 prmSize;
    Uint32 tableSize[3];
    Uint32 reqdPrmSize;
    CSL_IpipeGammaConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gamma;
    Uint32 *pTable[3];

    prmSize = sizeof(*pPrm);
    tableSize[0] = sizeof(gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gammaTableR);
    tableSize[1] = sizeof(gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gammaTableG);
    tableSize[2] = sizeof(gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gammaTableB);

    pTable[0] = gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gammaTableR;
    pTable[1] = gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gammaTableG;
    pTable[2] = gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gammaTableB;

    reqdPrmSize = prmSize + tableSize[0] + tableSize[1] + tableSize[2];

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, prmSize);

    memcpy(pTable[0], (Uint8 *)cmdInfo->prm + prmSize                               , tableSize[0]);
    memcpy(pTable[1], (Uint8 *)cmdInfo->prm + prmSize + tableSize[0]                , tableSize[1]);
    memcpy(pTable[2], (Uint8 *)cmdInfo->prm + prmSize + tableSize[0] + tableSize[1] , tableSize[2]);

    pPrm->tableR = pTable[0];
    pPrm->tableG = pTable[1];
    pPrm->tableB = pTable[2];

    retVal =  CSL_ipipeSetGammaConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeRgb2Rgb2(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeRgb2RgbConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2rgb2;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal =  CSL_ipipeSetRgb2Rgb2Config(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeLut3d(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_Ipipe3dLutConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.lut3d;
    Uint32 *pTable = gIMAGE_TUNE_ctrl.curPrm.ipipePrm.lut3dTable;
    Uint32 prmSize = sizeof(*pPrm);
    Uint32 tableSize = sizeof(gIMAGE_TUNE_ctrl.curPrm.ipipePrm.lut3dTable);
    Uint32 reqdPrmSize = prmSize + tableSize;

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);
    memcpy(pTable, (Uint8*)cmdInfo->prm + prmSize, tableSize);
    pPrm->table = pTable;
    retVal =  CSL_ipipeSet3dLutConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeRgb2Yuv(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeRgb2YuvConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2yuv;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal =  CSL_ipipeSetRgb2YuvConfig(&gCSL_ipipeHndl, pPrm);
    OSA_printf(" \r\n gIMAGE_TUNE_ctrl.curPrm.ipipePrm %d, %d, %d ", gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2yuv.matrix[0][0],gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2yuv.matrix[1][1], gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2yuv.offset[0]);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeCntBrt(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeCntBrtConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.cntBrt;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal =  CSL_ipipeSetCntBrtConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeGbce(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeGbceConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gbce;
    Uint32 *pTable = gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gbceTable;
    Uint32 prmSize = sizeof(*pPrm);
    Uint32 tableSize = sizeof(gIMAGE_TUNE_ctrl.curPrm.ipipePrm.gbceTable);
    Uint32 reqdPrmSize = prmSize + tableSize;

    if (cmdInfo->prmSize != reqdPrmSize)
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, prmSize);
    memcpy(pTable, (Uint8*)cmdInfo->prm + prmSize, tableSize);

    pPrm->gainTable = pTable;

    retVal =  CSL_ipipeSetGbceConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeEdgeEnhance(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeEdgeEnhanceConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.yee;
    Uint32 *pTable = gIMAGE_TUNE_ctrl.curPrm.ipipePrm.yeeTable;
    Uint32 prmSize = sizeof(*pPrm);
    Uint32 tableSize = sizeof(gIMAGE_TUNE_ctrl.curPrm.ipipePrm.yeeTable);
    Uint32 reqdPrmSize = prmSize + tableSize;

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, prmSize);
    memcpy(pTable, (Uint8*)cmdInfo->prm + prmSize, tableSize);

    pPrm->table = pTable;

    retVal =  CSL_ipipeSetEdgeEnhanceConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeCromaArtifactReduce(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeChromaArtifactReduceConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.car;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize)
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal =  CSL_ipipeSetChromaArtifactReduceConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}

int IMAGE_TUNE_CmdExecuteIpipeChromaGainSupress(IMAGE_TUNE_CmdInfo *cmdInfo, IMAGE_TUNE_CmdInfo *statusInfo)
{
    int retVal;
    CSL_IpipeChromaGainSupressConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.cgs;
    Uint32 reqdPrmSize = sizeof(*pPrm);

    if (cmdInfo->prmSize != reqdPrmSize )
    {
#ifdef IMAGE_TUNE_CMD_HANDLER_DEBUG
        OSA_printf(" IMAGE TUNE SERVER: Received parameter size (%d != %d) mismatch ERROR for CMD 0x%04x\n", cmdInfo->prmSize, reqdPrmSize, cmdInfo->commandId);
#endif
        return OSA_EFAIL;
    }

    memcpy(pPrm, cmdInfo->prm, reqdPrmSize);

    retVal =  CSL_ipipeSetChromaGainSupressConfig(&gCSL_ipipeHndl, pPrm);

    return retVal;
}


//ANR - Test
int IMAGE_TUNE_CmdExecuteIpipeRgb2Yuv_new(Uint32 id)
{
    CSL_IpipeRgb2YuvConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2yuv;
    int retVal =  CSL_ipipeSetRgb2YuvConfig(&gCSL_ipipeHndl, pPrm);
    OSA_printf(" \r\n gIMAGE_TUNE_ctrl.curPrm.ipipePrm %d, %d, %d ", 
               gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2yuv.matrix[0][0],
               gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2yuv.matrix[1][1], 
               gIMAGE_TUNE_ctrl.curPrm.ipipePrm.rgb2yuv.offset[0]);
    return retVal;
}

int IMAGE_TUNE_IPIPE_LoadParams(Uint32 id)
{
    CSL_IpipeChromaGainSupressConfig *pPrm = &gIMAGE_TUNE_ctrl.curPrm.ipipePrm.cgs;
    return CSL_ipipeSetChromaGainSupressConfig(&gCSL_ipipeHndl, pPrm);
}



