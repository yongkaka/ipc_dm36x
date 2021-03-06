/*
    DM360 Evaluation Software

    (c)Texas Instruments 2007
*/
#include <csl_ccdc.h>

CSL_Status CSL_ccdcHwSetup(CSL_CcdcHandle hndl, CSL_CcdcHwSetup * data)
{
  if (hndl == NULL || data == NULL)
    return CSL_EFAIL;

  if (CSL_ccdcSetInDataConfig(hndl, data->inDataConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_HLPF, CSL_ISIF_MODESET_HLPF_RESETVAL); //InDataConfig
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_INPMOD, CSL_ISIF_MODESET_INPMOD_RESETVAL);
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_DPOL, CSL_ISIF_MODESET_DPOL_RESETVAL);
    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_Y8POS, CSL_ISIF_CCDCFG_Y8POS_RESETVAL);
    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_GWDI, CSL_ISIF_CGAMMAWD_GWDI_RESETVAL);
  }

  if (CSL_ccdcSetSyncConfig(hndl, data->syncConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_CCDMD, CSL_ISIF_MODESET_CCDMD_RESETVAL); //  SyncConfig
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_SWEN, CSL_ISIF_MODESET_SWEN_RESETVAL);

    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_FIPOL, CSL_ISIF_MODESET_FIPOL_RESETVAL);
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_HDPOL, CSL_ISIF_MODESET_HDPOL_RESETVAL);
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_VDPOL, CSL_ISIF_MODESET_VDPOL_RESETVAL);
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_HDVDD, CSL_ISIF_MODESET_HDVDD_RESETVAL);
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_FIDD, CSL_ISIF_MODESET_FIDD_RESETVAL);

    CSL_FINS(hndl->regs->HDW, ISIF_HDW_HDW, CSL_ISIF_HDW_HDW_RESETVAL);
    CSL_FINS(hndl->regs->VDW, ISIF_VDW_VDW, CSL_ISIF_VDW_VDW_RESETVAL);

    CSL_FINS(hndl->regs->PPLN, ISIF_PPLN_PPLN, CSL_ISIF_PPLN_PPLN_RESETVAL);
    CSL_FINS(hndl->regs->LPFR, ISIF_LPFR_LPFR, CSL_ISIF_LPFR_LPFR_RESETVAL);
  }

  if (CSL_ccdcSetMiscConfig(hndl, data->miscConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_CFAP, CSL_ISIF_CGAMMAWD_CFAP_RESETVAL);  // misc config

    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_VDLC, CSL_ISIF_CCDCFG_VDLC_RESETVAL);
    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_MSBINVO, CSL_ISIF_CCDCFG_MSBINVO_RESETVAL);
    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_MSBINVI, CSL_ISIF_CCDCFG_MSBINVI_RESETVAL);

    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_EXTRG, CSL_ISIF_CCDCFG_EXTRG_RESETVAL);
    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_TRGSEL, CSL_ISIF_CCDCFG_TRGSEL_RESETVAL);

    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_WENLOG, CSL_ISIF_CCDCFG_WENLOG_RESETVAL);
    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_FIDMD, CSL_ISIF_CCDCFG_FIDMD_RESETVAL);

    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_YCINSWP, CSL_ISIF_CCDCFG_YCINSWP_RESETVAL);
    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_YCOUTSWP, CSL_ISIF_CCDCFG_YCOUTSWP_RESETVAL);
  }

  if (CSL_ccdcSetColPatConfig(hndl, data->colPatConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->CCOLP, ISIF_CCOLP_CP01_0, CSL_ISIF_CCOLP_CP01_0_RESETVAL); //colour pattern congfig
    CSL_FINS(hndl->regs->CCOLP, ISIF_CCOLP_CP03_2, CSL_ISIF_CCOLP_CP03_2_RESETVAL);
    CSL_FINS(hndl->regs->CCOLP, ISIF_CCOLP_CP05_4, CSL_ISIF_CCOLP_CP05_4_RESETVAL);
    CSL_FINS(hndl->regs->CCOLP, ISIF_CCOLP_CP07_6, CSL_ISIF_CCOLP_CP07_6_RESETVAL);

    CSL_FINS(hndl->regs->CCOLP, ISIF_CCOLP_CP11_0, CSL_ISIF_CCOLP_CP11_0_RESETVAL);
    CSL_FINS(hndl->regs->CCOLP, ISIF_CCOLP_CP13_2, CSL_ISIF_CCOLP_CP13_2_RESETVAL);
    CSL_FINS(hndl->regs->CCOLP, ISIF_CCOLP_CP15_4, CSL_ISIF_CCOLP_CP15_4_RESETVAL);
    CSL_FINS(hndl->regs->CCOLP, ISIF_CCOLP_CP17_6, CSL_ISIF_CCOLP_CP17_6_RESETVAL);
  }

  if (CSL_ccdcSetLinerizationConfig(hndl, data->linerizationConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->LINCFG0, ISIF_LINCFG0_LINEN, CSL_ISIF_LINCFG0_LINEN_RESETVAL);
  }

  if (CSL_ccdcSetFmtCscInFrameConfig(hndl, data->fmtInFrameConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->FMTSPH, ISIF_FMTSPH_FMTSPH, CSL_ISIF_FMTSPH_FMTSPH_RESETVAL);  // fmt csc inframe config
    CSL_FINS(hndl->regs->FMTLNH, ISIF_FMTLNH_FMTLNH, CSL_ISIF_FMTLNH_FMTLNH_RESETVAL);
    CSL_FINS(hndl->regs->FMTSLV, ISIF_FMTSLV_FMTSLV, CSL_ISIF_FMTSLV_FMTSLV_RESETVAL);
    CSL_FINS(hndl->regs->FMTLNV, ISIF_FMTLNV_FMTLNV, CSL_ISIF_FMTLNV_FMTLNV_RESETVAL);
  }

  if (CSL_ccdcSetFmtConfig(hndl, data->fmtConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->FMTCFG, ISIF_FMTCFG_FMTEN, CSL_ISIF_FMTCFG_FMTEN_RESETVAL);
  }

  if (CSL_ccdcSetCscConfig(hndl, data->cscConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->CSCCTL, ISIF_CSCCTL_CSCEN, CSL_ISIF_CSCCTL_CSCEN_RESETVAL);
  }

  if (CSL_ccdcSetClampConfig(hndl, data->clampConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->CLAMPCFG, ISIF_CLAMPCFG_CLEN, CSL_ISIF_CLAMPCFG_CLEN_RESETVAL);
  }

  if (CSL_ccdcSetDfcLscOffsetConfig(hndl, data->dfcLscOffsetConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->DATAHOFST, ISIF_DATAHOFST_HOFST, CSL_ISIF_DATAHOFST_HOFST_RESETVAL); //lsc offset config
    CSL_FINS(hndl->regs->DATAVOFST, ISIF_DATAVOFST_VOFST, CSL_ISIF_DATAVOFST_VOFST_RESETVAL);
  }

  if (CSL_ccdcSetDfcConfig(hndl, data->dfcConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->DFCCTL, ISIF_DFCCTL_VDFCEN, CSL_ISIF_DFCCTL_VDFCEN_RESETVAL);
  }

  if (CSL_ccdcSetLscConfig(hndl, data->lscConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->DLSCCFG, ISIF_DLSCCFG_ENABLE, CSL_ISIF_DLSCCFG_ENABLE_RESETVAL);
  }

  if (CSL_ccdcSetGainOffsetConfig(hndl, data->gainOffsetConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->CRGAIN, ISIF_CRGAIN_CGR, CSL_ISIF_CRGAIN_CGR_RESETVAL);  //gain offset config
    CSL_FINS(hndl->regs->CGRGAIN, ISIF_CGRGAIN_CGGR, CSL_ISIF_CGRGAIN_CGGR_RESETVAL);
    CSL_FINS(hndl->regs->CGBGAIN, ISIF_CGBGAIN_CGGB, CSL_ISIF_CGBGAIN_CGGB_RESETVAL);
    CSL_FINS(hndl->regs->CBGAIN, ISIF_CBGAIN_CGB, CSL_ISIF_CBGAIN_CGB_RESETVAL);

    CSL_FINS(hndl->regs->COFSTA, ISIF_COFSTA_COFT, CSL_ISIF_COFSTA_COFT_RESETVAL);

    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_WBEN1, CSL_ISIF_CGAMMAWD_WBEN1_RESETVAL);
    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_OFSTEN1, CSL_ISIF_CGAMMAWD_OFSTEN1_RESETVAL);

    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_WBEN2, CSL_ISIF_CGAMMAWD_WBEN2_RESETVAL);
    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_OFSTEN2, CSL_ISIF_CGAMMAWD_OFSTEN2_RESETVAL);

    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_WBEN0, CSL_ISIF_CGAMMAWD_WBEN0_RESETVAL);
    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_OFSTEN0, CSL_ISIF_CGAMMAWD_OFSTEN0_RESETVAL);
  }

  if (CSL_ccdcSetSdramOutConfig(hndl, data->sdramOutConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->MODESET, ISIF_MODESET_CCDW, CSL_ISIF_MODESET_CCDW_RESETVAL); //SetSdramOutConfig

    CSL_FINS(hndl->regs->CULH, ISIF_CULH_CLHE, CSL_ISIF_CULH_CLHE_RESETVAL);
    CSL_FINS(hndl->regs->CULH, ISIF_CULH_CLHO, CSL_ISIF_CULH_CLHO_RESETVAL);
    CSL_FINS(hndl->regs->CULV, ISIF_CULV_CULV, CSL_ISIF_CULV_CULV_RESETVAL);

    CSL_FINS(hndl->regs->HSIZE, ISIF_HSIZE_HSIZE, CSL_ISIF_HSIZE_HSIZE_RESETVAL); // 32 bit aligned
    CSL_FINS(hndl->regs->HSIZE, ISIF_HSIZE_ADCR, CSL_ISIF_HSIZE_ADCR_RESETVAL);

    CSL_FINS(hndl->regs->SDOFST, ISIF_SDOFST_FIINV, CSL_ISIF_SDOFST_FIINV_RESETVAL);
    CSL_FINS(hndl->regs->SDOFST, ISIF_SDOFST_FOFST, CSL_ISIF_SDOFST_FOFST_RESETVAL);
    CSL_FINS(hndl->regs->SDOFST, ISIF_SDOFST_LOFTS0, CSL_ISIF_SDOFST_LOFTS0_RESETVAL);
    CSL_FINS(hndl->regs->SDOFST, ISIF_SDOFST_LOFTS1, CSL_ISIF_SDOFST_LOFTS1_RESETVAL);
    CSL_FINS(hndl->regs->SDOFST, ISIF_SDOFST_LOFTS2, CSL_ISIF_SDOFST_LOFTS2_RESETVAL);
    CSL_FINS(hndl->regs->SDOFST, ISIF_SDOFST_LOFTS3, CSL_ISIF_SDOFST_LOFTS3_RESETVAL);

    CSL_FINS(hndl->regs->CADU, ISIF_CADU_CADU, CSL_ISIF_CADU_CADU_RESETVAL);
    CSL_FINS(hndl->regs->CADU, ISIF_CADL_CADL, CSL_ISIF_CADL_CADL_RESETVAL);

    CSL_FINS(hndl->regs->CGAMMAWD, ISIF_CGAMMAWD_CCDTBL, CSL_ISIF_CGAMMAWD_CCDTBL_RESETVAL);
    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_BSWD, CSL_ISIF_CCDCFG_BSWD_RESETVAL);

    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_SDRPACK, CSL_ISIF_CCDCFG_SDRPACK_RESETVAL);
  }

  if (CSL_ccdcSetDpcmConfig(hndl, data->dpcmConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->MISC, ISIF_MISC_DPCMEN, CSL_ISIF_MISC_DPCMEN_RESETVAL);
  }

  if (CSL_ccdcSetRec656Config(hndl, data->rec656Config) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->REC656IF, ISIF_REC656IF_R656ON, CSL_ISIF_REC656IF_R656ON_RESETVAL);  // SetRec656Config
    CSL_FINS(hndl->regs->REC656IF, ISIF_REC656IF_ECCFVH, CSL_ISIF_REC656IF_ECCFVH_RESETVAL);
    CSL_FINS(hndl->regs->CCDCFG, ISIF_CCDCFG_BW656, CSL_ISIF_CCDCFG_BW656_RESETVAL);
  }

  if (CSL_ccdcSetFlashConfig(hndl, data->flashConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->FLSHCFG0, ISIF_FLSHCFG0_FLSHEN, CSL_ISIF_FLSHCFG0_FLSHEN_RESETVAL);
  }

  if (CSL_ccdcSetVdIntConfig(hndl, data->vdIntConfig) != CSL_SOK && data->bypassModuleIfNullConfig == TRUE) {
    CSL_FINS(hndl->regs->VDINT0, ISIF_VDINT0_CVD0, CSL_ISIF_VDINT0_CVD0_RESETVAL);  //SetVdIntConfig
    CSL_FINS(hndl->regs->VDINT1, ISIF_VDINT1_CVD1, CSL_ISIF_VDINT1_CVD1_RESETVAL);
    CSL_FINS(hndl->regs->VDINT2, ISIF_VDINT2_CVD2, CSL_ISIF_VDINT2_CVD2_RESETVAL);
  }

  CSL_FINS(hndl->regs->SYNCEN, ISIF_SYNCEN_DWEN, data->sdramOutEnable);
  CSL_FINS(hndl->regs->SYNCEN, ISIF_SYNCEN_SYEN, data->enable);

  return CSL_SOK;
}
