
/**
 * Copyright (c) 2019 Pensando Systems, Inc.
 *
 * @file    asicerrord_delphi.cc
 *
 * @brief   This file handles delphi events
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "gen/proto/asicerrord.delphi.hpp"

delphi::objects::ppappa0intbndl0metrics_t ppappa0intbndl0metrics;
delphi::objects::ppappa0intbndl1metrics_t ppappa0intbndl1metrics;
delphi::objects::ppappa0inteccmetrics_t ppappa0inteccmetrics;
delphi::objects::ppappa0intfifo1metrics_t ppappa0intfifo1metrics;
delphi::objects::ppappa0intfifo2metrics_t ppappa0intfifo2metrics;
delphi::objects::ppappa0intpe0metrics_t ppappa0intpe0metrics;
delphi::objects::ppappa0intpe1metrics_t ppappa0intpe1metrics;
delphi::objects::ppappa0intpe2metrics_t ppappa0intpe2metrics;
delphi::objects::ppappa0intpe3metrics_t ppappa0intpe3metrics;
delphi::objects::ppappa0intpe4metrics_t ppappa0intpe4metrics;
delphi::objects::ppappa0intpe5metrics_t ppappa0intpe5metrics;
delphi::objects::ppappa0intpe6metrics_t ppappa0intpe6metrics;
delphi::objects::ppappa0intpe7metrics_t ppappa0intpe7metrics;
delphi::objects::ppappa0intpe8metrics_t ppappa0intpe8metrics;
delphi::objects::ppappa0intpe9metrics_t ppappa0intpe9metrics;
delphi::objects::ppappa0intpametrics_t ppappa0intpametrics;
delphi::objects::ppappa0intswphvmemmetrics_t ppappa0intswphvmemmetrics;
delphi::objects::ppappa0intintfmetrics_t ppappa0intintfmetrics;
delphi::objects::ppappa1intbndl0metrics_t ppappa1intbndl0metrics;
delphi::objects::ppappa1intbndl1metrics_t ppappa1intbndl1metrics;
delphi::objects::ppappa1inteccmetrics_t ppappa1inteccmetrics;
delphi::objects::ppappa1intfifo1metrics_t ppappa1intfifo1metrics;
delphi::objects::ppappa1intfifo2metrics_t ppappa1intfifo2metrics;
delphi::objects::ppappa1intpe0metrics_t ppappa1intpe0metrics;
delphi::objects::ppappa1intpe1metrics_t ppappa1intpe1metrics;
delphi::objects::ppappa1intpe2metrics_t ppappa1intpe2metrics;
delphi::objects::ppappa1intpe3metrics_t ppappa1intpe3metrics;
delphi::objects::ppappa1intpe4metrics_t ppappa1intpe4metrics;
delphi::objects::ppappa1intpe5metrics_t ppappa1intpe5metrics;
delphi::objects::ppappa1intpe6metrics_t ppappa1intpe6metrics;
delphi::objects::ppappa1intpe7metrics_t ppappa1intpe7metrics;
delphi::objects::ppappa1intpe8metrics_t ppappa1intpe8metrics;
delphi::objects::ppappa1intpe9metrics_t ppappa1intpe9metrics;
delphi::objects::ppappa1intpametrics_t ppappa1intpametrics;
delphi::objects::ppappa1intswphvmemmetrics_t ppappa1intswphvmemmetrics;
delphi::objects::ppappa1intintfmetrics_t ppappa1intintfmetrics;
delphi::objects::sgite0interrmetrics_t sgite0interrmetrics;
delphi::objects::sgite0intinfometrics_t sgite0intinfometrics;
delphi::objects::sgite1interrmetrics_t sgite1interrmetrics;
delphi::objects::sgite1intinfometrics_t sgite1intinfometrics;
delphi::objects::sgite2interrmetrics_t sgite2interrmetrics;
delphi::objects::sgite2intinfometrics_t sgite2intinfometrics;
delphi::objects::sgite3interrmetrics_t sgite3interrmetrics;
delphi::objects::sgite3intinfometrics_t sgite3intinfometrics;
delphi::objects::sgite4interrmetrics_t sgite4interrmetrics;
delphi::objects::sgite4intinfometrics_t sgite4intinfometrics;
delphi::objects::sgite5interrmetrics_t sgite5interrmetrics;
delphi::objects::sgite5intinfometrics_t sgite5intinfometrics;
delphi::objects::sgimpu0interrmetrics_t sgimpu0interrmetrics;
delphi::objects::sgimpu0intinfometrics_t sgimpu0intinfometrics;
delphi::objects::sgimpu1interrmetrics_t sgimpu1interrmetrics;
delphi::objects::sgimpu1intinfometrics_t sgimpu1intinfometrics;
delphi::objects::sgimpu2interrmetrics_t sgimpu2interrmetrics;
delphi::objects::sgimpu2intinfometrics_t sgimpu2intinfometrics;
delphi::objects::sgimpu3interrmetrics_t sgimpu3interrmetrics;
delphi::objects::sgimpu3intinfometrics_t sgimpu3intinfometrics;
delphi::objects::sgimpu4interrmetrics_t sgimpu4interrmetrics;
delphi::objects::sgimpu4intinfometrics_t sgimpu4intinfometrics;
delphi::objects::sgimpu5interrmetrics_t sgimpu5interrmetrics;
delphi::objects::sgimpu5intinfometrics_t sgimpu5intinfometrics;
delphi::objects::rpcpicsintpicsmetrics_t rpcpicsintpicsmetrics;
delphi::objects::rpcpicsintbadaddrmetrics_t rpcpicsintbadaddrmetrics;
delphi::objects::rpcpicsintbgmetrics_t rpcpicsintbgmetrics;
delphi::objects::rpcpicspiccintpiccmetrics_t rpcpicspiccintpiccmetrics;
delphi::objects::intrintrintintreccmetrics_t intrintrintintreccmetrics;
delphi::objects::pxbpxbinttgteccmetrics_t pxbpxbinttgteccmetrics;
delphi::objects::pxbpxbintitreccmetrics_t pxbpxbintitreccmetrics;
delphi::objects::pxbpxbinterrmetrics_t pxbpxbinterrmetrics;
delphi::objects::sgete0interrmetrics_t sgete0interrmetrics;
delphi::objects::sgete0intinfometrics_t sgete0intinfometrics;
delphi::objects::sgete1interrmetrics_t sgete1interrmetrics;
delphi::objects::sgete1intinfometrics_t sgete1intinfometrics;
delphi::objects::sgete2interrmetrics_t sgete2interrmetrics;
delphi::objects::sgete2intinfometrics_t sgete2intinfometrics;
delphi::objects::sgete3interrmetrics_t sgete3interrmetrics;
delphi::objects::sgete3intinfometrics_t sgete3intinfometrics;
delphi::objects::sgete4interrmetrics_t sgete4interrmetrics;
delphi::objects::sgete4intinfometrics_t sgete4intinfometrics;
delphi::objects::sgete5interrmetrics_t sgete5interrmetrics;
delphi::objects::sgete5intinfometrics_t sgete5intinfometrics;
delphi::objects::sgempu0interrmetrics_t sgempu0interrmetrics;
delphi::objects::sgempu0intinfometrics_t sgempu0intinfometrics;
delphi::objects::sgempu1interrmetrics_t sgempu1interrmetrics;
delphi::objects::sgempu1intinfometrics_t sgempu1intinfometrics;
delphi::objects::sgempu2interrmetrics_t sgempu2interrmetrics;
delphi::objects::sgempu2intinfometrics_t sgempu2intinfometrics;
delphi::objects::sgempu3interrmetrics_t sgempu3interrmetrics;
delphi::objects::sgempu3intinfometrics_t sgempu3intinfometrics;
delphi::objects::sgempu4interrmetrics_t sgempu4interrmetrics;
delphi::objects::sgempu4intinfometrics_t sgempu4intinfometrics;
delphi::objects::sgempu5interrmetrics_t sgempu5interrmetrics;
delphi::objects::sgempu5intinfometrics_t sgempu5intinfometrics;
delphi::objects::prprintreg1metrics_t prprintreg1metrics;
delphi::objects::prprpspintinfometrics_t prprpspintinfometrics;
delphi::objects::prprpspinterrmetrics_t prprpspinterrmetrics;
delphi::objects::prprpspintfatalmetrics_t prprpspintfatalmetrics;
delphi::objects::prprpspintlifqstatemapmetrics_t prprpspintlifqstatemapmetrics;
delphi::objects::prprpspintswphvmemmetrics_t prprpspintswphvmemmetrics;
delphi::objects::prprprdinteccmetrics_t prprprdinteccmetrics;
delphi::objects::prprprdintfifometrics_t prprprdintfifometrics;
delphi::objects::prprprdintgrp1metrics_t prprprdintgrp1metrics;
delphi::objects::prprprdintgrp2metrics_t prprprdintgrp2metrics;
delphi::objects::prprprdintintfmetrics_t prprprdintintfmetrics;
delphi::objects::ppppintppmetrics_t ppppintppmetrics;
delphi::objects::ppppportp0intpeccmetrics_t ppppportp0intpeccmetrics;
delphi::objects::ppppportp1intpeccmetrics_t ppppportp1intpeccmetrics;
delphi::objects::ppppportp2intpeccmetrics_t ppppportp2intpeccmetrics;
delphi::objects::ppppportp3intpeccmetrics_t ppppportp3intpeccmetrics;
delphi::objects::ppppportp4intpeccmetrics_t ppppportp4intpeccmetrics;
delphi::objects::ppppportp5intpeccmetrics_t ppppportp5intpeccmetrics;
delphi::objects::ppppportp6intpeccmetrics_t ppppportp6intpeccmetrics;
delphi::objects::ppppportp7intpeccmetrics_t ppppportp7intpeccmetrics;
delphi::objects::ppppportc0intcmacmetrics_t ppppportc0intcmacmetrics;
delphi::objects::ppppportc0intceccmetrics_t ppppportc0intceccmetrics;
delphi::objects::ppppportc1intcmacmetrics_t ppppportc1intcmacmetrics;
delphi::objects::ppppportc1intceccmetrics_t ppppportc1intceccmetrics;
delphi::objects::ppppportc2intcmacmetrics_t ppppportc2intcmacmetrics;
delphi::objects::ppppportc2intceccmetrics_t ppppportc2intceccmetrics;
delphi::objects::ppppportc3intcmacmetrics_t ppppportc3intcmacmetrics;
delphi::objects::ppppportc3intceccmetrics_t ppppportc3intceccmetrics;
delphi::objects::ppppportc4intcmacmetrics_t ppppportc4intcmacmetrics;
delphi::objects::ppppportc4intceccmetrics_t ppppportc4intceccmetrics;
delphi::objects::ppppportc5intcmacmetrics_t ppppportc5intcmacmetrics;
delphi::objects::ppppportc5intceccmetrics_t ppppportc5intceccmetrics;
delphi::objects::ppppportc6intcmacmetrics_t ppppportc6intcmacmetrics;
delphi::objects::ppppportc6intceccmetrics_t ppppportc6intceccmetrics;
delphi::objects::ppppportc7intcmacmetrics_t ppppportc7intcmacmetrics;
delphi::objects::ppppportc7intceccmetrics_t ppppportc7intceccmetrics;
delphi::objects::ptptintreg1metrics_t ptptintreg1metrics;
delphi::objects::ptptpspintinfometrics_t ptptpspintinfometrics;
delphi::objects::ptptpspinterrmetrics_t ptptpspinterrmetrics;
delphi::objects::ptptpspintfatalmetrics_t ptptpspintfatalmetrics;
delphi::objects::ptptpspintlifqstatemapmetrics_t ptptpspintlifqstatemapmetrics;
delphi::objects::ptptpspintswphvmemmetrics_t ptptpspintswphvmemmetrics;
delphi::objects::ptptptdinteccmetrics_t ptptptdinteccmetrics;
delphi::objects::ptptptdintfifometrics_t ptptptdintfifometrics;
delphi::objects::ptptptdintgrp1metrics_t ptptptdintgrp1metrics;
delphi::objects::ptptptdintgrp2metrics_t ptptptdintgrp2metrics;
delphi::objects::ptptptdintintfmetrics_t ptptptdintintfmetrics;
delphi::objects::pcrte0interrmetrics_t pcrte0interrmetrics;
delphi::objects::pcrte0intinfometrics_t pcrte0intinfometrics;
delphi::objects::pcrte1interrmetrics_t pcrte1interrmetrics;
delphi::objects::pcrte1intinfometrics_t pcrte1intinfometrics;
delphi::objects::pcrte2interrmetrics_t pcrte2interrmetrics;
delphi::objects::pcrte2intinfometrics_t pcrte2intinfometrics;
delphi::objects::pcrte3interrmetrics_t pcrte3interrmetrics;
delphi::objects::pcrte3intinfometrics_t pcrte3intinfometrics;
delphi::objects::pcrte4interrmetrics_t pcrte4interrmetrics;
delphi::objects::pcrte4intinfometrics_t pcrte4intinfometrics;
delphi::objects::pcrte5interrmetrics_t pcrte5interrmetrics;
delphi::objects::pcrte5intinfometrics_t pcrte5intinfometrics;
delphi::objects::pcrte6interrmetrics_t pcrte6interrmetrics;
delphi::objects::pcrte6intinfometrics_t pcrte6intinfometrics;
delphi::objects::pcrte7interrmetrics_t pcrte7interrmetrics;
delphi::objects::pcrte7intinfometrics_t pcrte7intinfometrics;
delphi::objects::pcrmpu0interrmetrics_t pcrmpu0interrmetrics;
delphi::objects::pcrmpu0intinfometrics_t pcrmpu0intinfometrics;
delphi::objects::pcrmpu1interrmetrics_t pcrmpu1interrmetrics;
delphi::objects::pcrmpu1intinfometrics_t pcrmpu1intinfometrics;
delphi::objects::pcrmpu2interrmetrics_t pcrmpu2interrmetrics;
delphi::objects::pcrmpu2intinfometrics_t pcrmpu2intinfometrics;
delphi::objects::pcrmpu3interrmetrics_t pcrmpu3interrmetrics;
delphi::objects::pcrmpu3intinfometrics_t pcrmpu3intinfometrics;
delphi::objects::pcrmpu4interrmetrics_t pcrmpu4interrmetrics;
delphi::objects::pcrmpu4intinfometrics_t pcrmpu4intinfometrics;
delphi::objects::pcrmpu5interrmetrics_t pcrmpu5interrmetrics;
delphi::objects::pcrmpu5intinfometrics_t pcrmpu5intinfometrics;
delphi::objects::pcrmpu6interrmetrics_t pcrmpu6interrmetrics;
delphi::objects::pcrmpu6intinfometrics_t pcrmpu6intinfometrics;
delphi::objects::pcrmpu7interrmetrics_t pcrmpu7interrmetrics;
delphi::objects::pcrmpu7intinfometrics_t pcrmpu7intinfometrics;
delphi::objects::txstxsintschmetrics_t txstxsintschmetrics;
delphi::objects::txstxsinttmrmetrics_t txstxsinttmrmetrics;
delphi::objects::txstxsintsramseccmetrics_t txstxsintsramseccmetrics;
delphi::objects::pctte0interrmetrics_t pctte0interrmetrics;
delphi::objects::pctte0intinfometrics_t pctte0intinfometrics;
delphi::objects::pctte1interrmetrics_t pctte1interrmetrics;
delphi::objects::pctte1intinfometrics_t pctte1intinfometrics;
delphi::objects::pctte2interrmetrics_t pctte2interrmetrics;
delphi::objects::pctte2intinfometrics_t pctte2intinfometrics;
delphi::objects::pctte3interrmetrics_t pctte3interrmetrics;
delphi::objects::pctte3intinfometrics_t pctte3intinfometrics;
delphi::objects::pctte4interrmetrics_t pctte4interrmetrics;
delphi::objects::pctte4intinfometrics_t pctte4intinfometrics;
delphi::objects::pctte5interrmetrics_t pctte5interrmetrics;
delphi::objects::pctte5intinfometrics_t pctte5intinfometrics;
delphi::objects::pctte6interrmetrics_t pctte6interrmetrics;
delphi::objects::pctte6intinfometrics_t pctte6intinfometrics;
delphi::objects::pctte7interrmetrics_t pctte7interrmetrics;
delphi::objects::pctte7intinfometrics_t pctte7intinfometrics;
delphi::objects::pctmpu0interrmetrics_t pctmpu0interrmetrics;
delphi::objects::pctmpu0intinfometrics_t pctmpu0intinfometrics;
delphi::objects::pctmpu1interrmetrics_t pctmpu1interrmetrics;
delphi::objects::pctmpu1intinfometrics_t pctmpu1intinfometrics;
delphi::objects::pctmpu2interrmetrics_t pctmpu2interrmetrics;
delphi::objects::pctmpu2intinfometrics_t pctmpu2intinfometrics;
delphi::objects::pctmpu3interrmetrics_t pctmpu3interrmetrics;
delphi::objects::pctmpu3intinfometrics_t pctmpu3intinfometrics;
delphi::objects::pctmpu4interrmetrics_t pctmpu4interrmetrics;
delphi::objects::pctmpu4intinfometrics_t pctmpu4intinfometrics;
delphi::objects::pctmpu5interrmetrics_t pctmpu5interrmetrics;
delphi::objects::pctmpu5intinfometrics_t pctmpu5intinfometrics;
delphi::objects::pctmpu6interrmetrics_t pctmpu6interrmetrics;
delphi::objects::pctmpu6intinfometrics_t pctmpu6intinfometrics;
delphi::objects::pctmpu7interrmetrics_t pctmpu7interrmetrics;
delphi::objects::pctmpu7intinfometrics_t pctmpu7intinfometrics;
delphi::objects::pbpbcinteccfc0metrics_t pbpbcinteccfc0metrics;
delphi::objects::pbpbcinteccll0metrics_t pbpbcinteccll0metrics;
delphi::objects::pbpbcinteccdesc0metrics_t pbpbcinteccdesc0metrics;
delphi::objects::pbpbcinteccfc1metrics_t pbpbcinteccfc1metrics;
delphi::objects::pbpbcinteccll1metrics_t pbpbcinteccll1metrics;
delphi::objects::pbpbcinteccdesc1metrics_t pbpbcinteccdesc1metrics;
delphi::objects::pbpbcintwrite0metrics_t pbpbcintwrite0metrics;
delphi::objects::pbpbcintwrite1metrics_t pbpbcintwrite1metrics;
delphi::objects::pbpbcintwrite2metrics_t pbpbcintwrite2metrics;
delphi::objects::pbpbcintwrite3metrics_t pbpbcintwrite3metrics;
delphi::objects::pbpbcintwrite4metrics_t pbpbcintwrite4metrics;
delphi::objects::pbpbcintwrite5metrics_t pbpbcintwrite5metrics;
delphi::objects::pbpbcintwrite6metrics_t pbpbcintwrite6metrics;
delphi::objects::pbpbcintwrite7metrics_t pbpbcintwrite7metrics;
delphi::objects::pbpbcintwrite8metrics_t pbpbcintwrite8metrics;
delphi::objects::pbpbcintwrite9metrics_t pbpbcintwrite9metrics;
delphi::objects::pbpbcintwrite10metrics_t pbpbcintwrite10metrics;
delphi::objects::pbpbcintwrite11metrics_t pbpbcintwrite11metrics;
delphi::objects::pbpbcinteccrcmetrics_t pbpbcinteccrcmetrics;
delphi::objects::pbpbcinteccpackmetrics_t pbpbcinteccpackmetrics;
delphi::objects::pbpbcinteccrwrmetrics_t pbpbcinteccrwrmetrics;
delphi::objects::pbpbcinteccschedmetrics_t pbpbcinteccschedmetrics;
delphi::objects::pbpbcinteccsidebandmetrics_t pbpbcinteccsidebandmetrics;
delphi::objects::pbpbcinteccncmetrics_t pbpbcinteccncmetrics;
delphi::objects::pbpbcinteccucmetrics_t pbpbcinteccucmetrics;
delphi::objects::pbpbcinteccportmoninmetrics_t pbpbcinteccportmoninmetrics;
delphi::objects::pbpbcinteccportmonoutmetrics_t pbpbcinteccportmonoutmetrics;
delphi::objects::pbpbcintrplmetrics_t pbpbcintrplmetrics;
delphi::objects::pbpbcintcreditunderflowmetrics_t pbpbcintcreditunderflowmetrics;
delphi::objects::pbpbcintpbusviolationinmetrics_t pbpbcintpbusviolationinmetrics;
delphi::objects::pbpbcintpbusviolationoutmetrics_t pbpbcintpbusviolationoutmetrics;
delphi::objects::pbpbchbmintecchbmmtumetrics_t pbpbchbmintecchbmmtumetrics;
delphi::objects::pbpbchbmintecchbmrbmetrics_t pbpbchbmintecchbmrbmetrics;
delphi::objects::pbpbchbmintecchbmwbmetrics_t pbpbchbmintecchbmwbmetrics;
delphi::objects::pbpbchbmintecchbmhtmetrics_t pbpbchbmintecchbmhtmetrics;
delphi::objects::pbpbchbminthbmxoffmetrics_t pbpbchbminthbmxoffmetrics;
delphi::objects::pbpbchbminthbmpbusviolationinmetrics_t pbpbchbminthbmpbusviolationinmetrics;
delphi::objects::pbpbchbminthbmpbusviolationoutmetrics_t pbpbchbminthbmpbusviolationoutmetrics;
delphi::objects::pbpbchbminthbmdropmetrics_t pbpbchbminthbmdropmetrics;
delphi::objects::pbpbchbminthbmstopmetrics_t pbpbchbminthbmstopmetrics;
delphi::objects::pbpbchbminthbmaxierrrspmetrics_t pbpbchbminthbmaxierrrspmetrics;
delphi::objects::pbpbchbminthbmdropemergencymetrics_t pbpbchbminthbmdropemergencymetrics;
delphi::objects::pbpbchbminthbmdropwriteackmetrics_t pbpbchbminthbmdropwriteackmetrics;
delphi::objects::pbpbchbminthbmdropctrlmetrics_t pbpbchbminthbmdropctrlmetrics;
delphi::objects::pbpbchbminthbmdropthresholdmetrics_t pbpbchbminthbmdropthresholdmetrics;
delphi::objects::pbpbchbminthbmtruncatenometrics_t pbpbchbminthbmtruncatenometrics;
delphi::objects::pmpbmintecccol0metrics_t pmpbmintecccol0metrics;
delphi::objects::pmpbmintecccol1metrics_t pmpbmintecccol1metrics;
delphi::objects::pmpbmintecccol2metrics_t pmpbmintecccol2metrics;
delphi::objects::pmpbmintecccol3metrics_t pmpbmintecccol3metrics;
delphi::objects::pmpbmintecccol4metrics_t pmpbmintecccol4metrics;
delphi::objects::dbwaintlifqstatemapmetrics_t dbwaintlifqstatemapmetrics;
delphi::objects::dbwaintdbmetrics_t dbwaintdbmetrics;
delphi::objects::ssipicsintpicsmetrics_t ssipicsintpicsmetrics;
delphi::objects::ssipicsintbadaddrmetrics_t ssipicsintbadaddrmetrics;
delphi::objects::ssipicsintbgmetrics_t ssipicsintbgmetrics;
delphi::objects::ssipicspiccintpiccmetrics_t ssipicspiccintpiccmetrics;
delphi::objects::ssepicsintpicsmetrics_t ssepicsintpicsmetrics;
delphi::objects::ssepicsintbadaddrmetrics_t ssepicsintbadaddrmetrics;
delphi::objects::ssepicsintbgmetrics_t ssepicsintbgmetrics;
delphi::objects::ssepicspiccintpiccmetrics_t ssepicspiccintpiccmetrics;
delphi::objects::bxbxintmacmetrics_t bxbxintmacmetrics;
delphi::objects::mdhensintipcoremetrics_t mdhensintipcoremetrics;
delphi::objects::mdhensintpkeccmetrics_t mdhensintpkeccmetrics;
delphi::objects::mdhensintdrbgintrameccmetrics_t mdhensintdrbgintrameccmetrics;
delphi::objects::mdhensintdrbgcryptorameccmetrics_t mdhensintdrbgcryptorameccmetrics;
delphi::objects::mdhensintaxierrmetrics_t mdhensintaxierrmetrics;
delphi::objects::tpcpicsintpicsmetrics_t tpcpicsintpicsmetrics;
delphi::objects::tpcpicsintbadaddrmetrics_t tpcpicsintbadaddrmetrics;
delphi::objects::tpcpicsintbgmetrics_t tpcpicsintbgmetrics;
delphi::objects::tpcpicspiccintpiccmetrics_t tpcpicspiccintpiccmetrics;
delphi::objects::dprdpr0intreg1metrics_t dprdpr0intreg1metrics;
delphi::objects::dprdpr0intreg2metrics_t dprdpr0intreg2metrics;
delphi::objects::dprdpr0intsramseccmetrics_t dprdpr0intsramseccmetrics;
delphi::objects::dprdpr0intfifometrics_t dprdpr0intfifometrics;
delphi::objects::dprdpr0intflopfifo0metrics_t dprdpr0intflopfifo0metrics;
delphi::objects::dprdpr0intflopfifo1metrics_t dprdpr0intflopfifo1metrics;
delphi::objects::dprdpr0intsparemetrics_t dprdpr0intsparemetrics;
delphi::objects::dprdpr0intcreditmetrics_t dprdpr0intcreditmetrics;
delphi::objects::dprdpr1intreg1metrics_t dprdpr1intreg1metrics;
delphi::objects::dprdpr1intreg2metrics_t dprdpr1intreg2metrics;
delphi::objects::dprdpr1intsramseccmetrics_t dprdpr1intsramseccmetrics;
delphi::objects::dprdpr1intfifometrics_t dprdpr1intfifometrics;
delphi::objects::dprdpr1intflopfifo0metrics_t dprdpr1intflopfifo0metrics;
delphi::objects::dprdpr1intflopfifo1metrics_t dprdpr1intflopfifo1metrics;
delphi::objects::dprdpr1intsparemetrics_t dprdpr1intsparemetrics;
delphi::objects::dprdpr1intcreditmetrics_t dprdpr1intcreditmetrics;
delphi::objects::mcmc0intmcmetrics_t mcmc0intmcmetrics;
delphi::objects::mcmc0mchintmcmetrics_t mcmc0mchintmcmetrics;
delphi::objects::mcmc1intmcmetrics_t mcmc1intmcmetrics;
delphi::objects::mcmc1mchintmcmetrics_t mcmc1mchintmcmetrics;
delphi::objects::mcmc2intmcmetrics_t mcmc2intmcmetrics;
delphi::objects::mcmc2mchintmcmetrics_t mcmc2mchintmcmetrics;
delphi::objects::mcmc3intmcmetrics_t mcmc3intmcmetrics;
delphi::objects::mcmc3mchintmcmetrics_t mcmc3mchintmcmetrics;
delphi::objects::mcmc4intmcmetrics_t mcmc4intmcmetrics;
delphi::objects::mcmc4mchintmcmetrics_t mcmc4mchintmcmetrics;
delphi::objects::mcmc5intmcmetrics_t mcmc5intmcmetrics;
delphi::objects::mcmc5mchintmcmetrics_t mcmc5mchintmcmetrics;
delphi::objects::mcmc6intmcmetrics_t mcmc6intmcmetrics;
delphi::objects::mcmc6mchintmcmetrics_t mcmc6mchintmcmetrics;
delphi::objects::mcmc7intmcmetrics_t mcmc7intmcmetrics;
delphi::objects::mcmc7mchintmcmetrics_t mcmc7mchintmcmetrics;
delphi::objects::dppdpp0intreg1metrics_t dppdpp0intreg1metrics;
delphi::objects::dppdpp0intreg2metrics_t dppdpp0intreg2metrics;
delphi::objects::dppdpp0intsramseccmetrics_t dppdpp0intsramseccmetrics;
delphi::objects::dppdpp0intfifometrics_t dppdpp0intfifometrics;
delphi::objects::dppdpp0intsparemetrics_t dppdpp0intsparemetrics;
delphi::objects::dppdpp0intcreditmetrics_t dppdpp0intcreditmetrics;
delphi::objects::dppdpp1intreg1metrics_t dppdpp1intreg1metrics;
delphi::objects::dppdpp1intreg2metrics_t dppdpp1intreg2metrics;
delphi::objects::dppdpp1intsramseccmetrics_t dppdpp1intsramseccmetrics;
delphi::objects::dppdpp1intfifometrics_t dppdpp1intfifometrics;
delphi::objects::dppdpp1intsparemetrics_t dppdpp1intsparemetrics;
delphi::objects::dppdpp1intcreditmetrics_t dppdpp1intcreditmetrics;
delphi::objects::semasemaintgroupsintregmetrics_t semasemaintgroupsintregmetrics;
delphi::objects::mpmpnsintcryptometrics_t mpmpnsintcryptometrics;
delphi::objects::msmsintmsmetrics_t msmsintmsmetrics;
delphi::objects::msmsintmiscmetrics_t msmsintmiscmetrics;
delphi::objects::msmsintesecuremetrics_t msmsintesecuremetrics;
delphi::objects::msmsintprp1metrics_t msmsintprp1metrics;
delphi::objects::msmsintprp2metrics_t msmsintprp2metrics;
delphi::objects::msmsintprp3metrics_t msmsintprp3metrics;
delphi::objects::msmsintprp4metrics_t msmsintprp4metrics;
delphi::objects::msmsintprp5metrics_t msmsintprp5metrics;
delphi::objects::msmsintgic0metrics_t msmsintgic0metrics;
delphi::objects::msmsintgic1metrics_t msmsintgic1metrics;
delphi::objects::msmsintgic2metrics_t msmsintgic2metrics;
delphi::objects::msmsintgic3metrics_t msmsintgic3metrics;
delphi::objects::msmsintgic4metrics_t msmsintgic4metrics;
delphi::objects::msmsintgic5metrics_t msmsintgic5metrics;
delphi::objects::msmsintgic6metrics_t msmsintgic6metrics;
delphi::objects::msmsintgic7metrics_t msmsintgic7metrics;
delphi::objects::msmsintgic8metrics_t msmsintgic8metrics;
delphi::objects::msmsintgic9metrics_t msmsintgic9metrics;
delphi::objects::msmsintgic10metrics_t msmsintgic10metrics;
delphi::objects::msmsintgic11metrics_t msmsintgic11metrics;
delphi::objects::msmsintgic12metrics_t msmsintgic12metrics;
delphi::objects::msmsintgic13metrics_t msmsintgic13metrics;
delphi::objects::msmsintgic14metrics_t msmsintgic14metrics;
delphi::objects::msmsintgic15metrics_t msmsintgic15metrics;
delphi::objects::msmsintgic16metrics_t msmsintgic16metrics;
delphi::objects::msmsintgic17metrics_t msmsintgic17metrics;
delphi::objects::msmsintgic18metrics_t msmsintgic18metrics;
delphi::objects::msmsintgic19metrics_t msmsintgic19metrics;
delphi::objects::msmsintgic20metrics_t msmsintgic20metrics;
delphi::objects::msmsintgic21metrics_t msmsintgic21metrics;
delphi::objects::msmsintgic22metrics_t msmsintgic22metrics;
delphi::objects::msmsintgic23metrics_t msmsintgic23metrics;
delphi::objects::msemintgroupsintregmetrics_t msemintgroupsintregmetrics;
delphi::objects::mxmx0intmacmetrics_t mxmx0intmacmetrics;
delphi::objects::mxmx0inteccmetrics_t mxmx0inteccmetrics;
delphi::objects::mxmx1intmacmetrics_t mxmx1intmacmetrics;
delphi::objects::mxmx1inteccmetrics_t mxmx1inteccmetrics;


sdk_ret_t interrupt_notify (uint64_t reg_id, uint64_t field_id)
{
    uint64_t key = 0;
    switch (reg_id) {
    case 1:
    {
        delphi::objects::ppappa0intbndl0metrics_t *reg = &ppappa0intbndl0metrics;
        switch (field_id) {
        case 2:
            reg->state_lkp_srch_hit_addr_range_err++;
            break;
        case 3:
            reg->state_lkp_srch_miss++;
            break;
        case 4:
            reg->state_lkp_srch_req_not_rdy++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intbndl0Metrics::Publish(key, reg);
        break;
    }
    case 2:
    {
        delphi::objects::ppappa0intbndl1metrics_t *reg = &ppappa0intbndl1metrics;
        switch (field_id) {
        case 2:
            reg->state_lkp_srch_hit_addr_range_err++;
            break;
        case 3:
            reg->state_lkp_srch_miss++;
            break;
        case 4:
            reg->state_lkp_srch_req_not_rdy++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intbndl1Metrics::Publish(key, reg);
        break;
    }
    case 3:
    {
        delphi::objects::ppappa0inteccmetrics_t *reg = &ppappa0inteccmetrics;
        switch (field_id) {
        case 2:
            reg->pkt_mem_uncorrectable++;
            break;
        case 3:
            reg->pkt_mem_correctable++;
            break;
        case 4:
            reg->bndl0_state_lkp_sram_uncorrectable++;
            break;
        case 5:
            reg->bndl0_state_lkp_sram_correctable++;
            break;
        case 6:
            reg->bndl1_state_lkp_sram_uncorrectable++;
            break;
        case 7:
            reg->bndl1_state_lkp_sram_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0inteccMetrics::Publish(key, reg);
        break;
    }
    case 4:
    {
        delphi::objects::ppappa0intfifo1metrics_t *reg = &ppappa0intfifo1metrics;
        switch (field_id) {
        case 2:
            reg->pe0_qctl_ff_ovflow++;
            break;
        case 3:
            reg->pe1_qctl_ff_ovflow++;
            break;
        case 4:
            reg->pe2_qctl_ff_ovflow++;
            break;
        case 5:
            reg->pe3_qctl_ff_ovflow++;
            break;
        case 6:
            reg->pe4_qctl_ff_ovflow++;
            break;
        case 7:
            reg->pe5_qctl_ff_ovflow++;
            break;
        case 8:
            reg->pe6_qctl_ff_ovflow++;
            break;
        case 9:
            reg->pe7_qctl_ff_ovflow++;
            break;
        case 10:
            reg->pe8_qctl_ff_ovflow++;
            break;
        case 11:
            reg->pe9_qctl_ff_ovflow++;
            break;
        case 12:
            reg->pe0_phv_ff_ovflow++;
            break;
        case 13:
            reg->pe1_phv_ff_ovflow++;
            break;
        case 14:
            reg->pe2_phv_ff_ovflow++;
            break;
        case 15:
            reg->pe3_phv_ff_ovflow++;
            break;
        case 16:
            reg->pe4_phv_ff_ovflow++;
            break;
        case 17:
            reg->pe5_phv_ff_ovflow++;
            break;
        case 18:
            reg->pe6_phv_ff_ovflow++;
            break;
        case 19:
            reg->pe7_phv_ff_ovflow++;
            break;
        case 20:
            reg->pe8_phv_ff_ovflow++;
            break;
        case 21:
            reg->pe9_phv_ff_ovflow++;
            break;
        case 22:
            reg->pe0_ohi_ff_ovflow++;
            break;
        case 23:
            reg->pe1_ohi_ff_ovflow++;
            break;
        case 24:
            reg->pe2_ohi_ff_ovflow++;
            break;
        case 25:
            reg->pe3_ohi_ff_ovflow++;
            break;
        case 26:
            reg->pe4_ohi_ff_ovflow++;
            break;
        case 27:
            reg->pe5_ohi_ff_ovflow++;
            break;
        case 28:
            reg->pe6_ohi_ff_ovflow++;
            break;
        case 29:
            reg->pe7_ohi_ff_ovflow++;
            break;
        case 30:
            reg->pe8_ohi_ff_ovflow++;
            break;
        case 31:
            reg->pe9_ohi_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intfifo1Metrics::Publish(key, reg);
        break;
    }
    case 5:
    {
        delphi::objects::ppappa0intfifo2metrics_t *reg = &ppappa0intfifo2metrics;
        switch (field_id) {
        case 2:
            reg->dp_if_ff_ovflow++;
            break;
        case 3:
            reg->ohi_if_ff_ovflow++;
            break;
        case 4:
            reg->ma_if_ff_ovflow++;
            break;
        case 5:
            reg->pb_if_ff_ovflow++;
            break;
        case 6:
            reg->pkt_mtu_ff_ovflow++;
            break;
        case 7:
            reg->outphv_ff_ovflow++;
            break;
        case 8:
            reg->outohi_ff_ovflow++;
            break;
        case 9:
            reg->chk_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intfifo2Metrics::Publish(key, reg);
        break;
    }
    case 6:
    {
        delphi::objects::ppappa0intpe0metrics_t *reg = &ppappa0intpe0metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe0Metrics::Publish(key, reg);
        break;
    }
    case 7:
    {
        delphi::objects::ppappa0intpe1metrics_t *reg = &ppappa0intpe1metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe1Metrics::Publish(key, reg);
        break;
    }
    case 8:
    {
        delphi::objects::ppappa0intpe2metrics_t *reg = &ppappa0intpe2metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe2Metrics::Publish(key, reg);
        break;
    }
    case 9:
    {
        delphi::objects::ppappa0intpe3metrics_t *reg = &ppappa0intpe3metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe3Metrics::Publish(key, reg);
        break;
    }
    case 10:
    {
        delphi::objects::ppappa0intpe4metrics_t *reg = &ppappa0intpe4metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe4Metrics::Publish(key, reg);
        break;
    }
    case 11:
    {
        delphi::objects::ppappa0intpe5metrics_t *reg = &ppappa0intpe5metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe5Metrics::Publish(key, reg);
        break;
    }
    case 12:
    {
        delphi::objects::ppappa0intpe6metrics_t *reg = &ppappa0intpe6metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe6Metrics::Publish(key, reg);
        break;
    }
    case 13:
    {
        delphi::objects::ppappa0intpe7metrics_t *reg = &ppappa0intpe7metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe7Metrics::Publish(key, reg);
        break;
    }
    case 14:
    {
        delphi::objects::ppappa0intpe8metrics_t *reg = &ppappa0intpe8metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe8Metrics::Publish(key, reg);
        break;
    }
    case 15:
    {
        delphi::objects::ppappa0intpe9metrics_t *reg = &ppappa0intpe9metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpe9Metrics::Publish(key, reg);
        break;
    }
    case 16:
    {
        delphi::objects::ppappa0intpametrics_t *reg = &ppappa0intpametrics;
        switch (field_id) {
        case 2:
            reg->reorder_phv_not_sop++;
            break;
        case 3:
            reg->csum0_not_enuf_bytes++;
            break;
        case 4:
            reg->csum0_start_more_than_end_offset++;
            break;
        case 5:
            reg->csum1_not_enuf_bytes++;
            break;
        case 6:
            reg->csum1_start_more_than_end_offset++;
            break;
        case 7:
            reg->csum2_not_enuf_bytes++;
            break;
        case 8:
            reg->csum2_start_more_than_end_offset++;
            break;
        case 9:
            reg->csum3_not_enuf_bytes++;
            break;
        case 10:
            reg->csum3_start_more_than_end_offset++;
            break;
        case 11:
            reg->csum4_not_enuf_bytes++;
            break;
        case 12:
            reg->csum4_start_more_than_end_offset++;
            break;
        case 13:
            reg->crc_not_enuf_bytes++;
            break;
        case 14:
            reg->crc_start_more_than_end_offset++;
            break;
        case 15:
            reg->chkr_phv_single_flit++;
            break;
        case 16:
            reg->chkr_phv_not_sop++;
            break;
        case 17:
            reg->chkr_pkt_not_sop++;
            break;
        case 18:
            reg->chkr_seq_id++;
            break;
        case 19:
            reg->preparse_line0_not_sop++;
            break;
        case 20:
            reg->preparse_dff_not_sop++;
            break;
        case 21:
            reg->preparse_dff_ovflow++;
            break;
        case 22:
            reg->preparse_eff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intpaMetrics::Publish(key, reg);
        break;
    }
    case 17:
    {
        delphi::objects::ppappa0intswphvmemmetrics_t *reg = &ppappa0intswphvmemmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_uncorrectable++;
            break;
        case 3:
            reg->ecc_correctable++;
            break;
        case 4:
            reg->phv_invalid_sram++;
            break;
        case 5:
            reg->phv_invalid_data++;
            break;
        case 6:
            reg->phv_done0++;
            break;
        case 7:
            reg->phv_done1++;
            break;
        case 8:
            reg->phv_done2++;
            break;
        case 9:
            reg->phv_done3++;
            break;
        case 10:
            reg->phv_done4++;
            break;
        case 11:
            reg->phv_done5++;
            break;
        case 12:
            reg->phv_done6++;
            break;
        case 13:
            reg->phv_done7++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intswphvmemMetrics::Publish(key, reg);
        break;
    }
    case 18:
    {
        delphi::objects::ppappa0intintfmetrics_t *reg = &ppappa0intintfmetrics;
        switch (field_id) {
        case 2:
            reg->pb_err++;
            break;
        case 3:
            reg->pb_sop_err++;
            break;
        case 4:
            reg->pb_eop_err++;
            break;
        case 5:
            reg->dp_err++;
            break;
        case 6:
            reg->dp_sop_err++;
            break;
        case 7:
            reg->dp_eop_err++;
            break;
        case 8:
            reg->ohi_err++;
            break;
        case 9:
            reg->ohi_sop_err++;
            break;
        case 10:
            reg->ohi_eop_err++;
            break;
        case 11:
            reg->sw_phv_err++;
            break;
        case 12:
            reg->sw_phv_sop_err++;
            break;
        case 13:
            reg->sw_phv_eop_err++;
            break;
        case 14:
            reg->ma_err++;
            break;
        case 15:
            reg->ma_sop_err++;
            break;
        case 16:
            reg->ma_eop_err++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa0intintfMetrics::Publish(key, reg);
        break;
    }
    case 20:
    {
        delphi::objects::ppappa1intbndl0metrics_t *reg = &ppappa1intbndl0metrics;
        switch (field_id) {
        case 2:
            reg->state_lkp_srch_hit_addr_range_err++;
            break;
        case 3:
            reg->state_lkp_srch_miss++;
            break;
        case 4:
            reg->state_lkp_srch_req_not_rdy++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intbndl0Metrics::Publish(key, reg);
        break;
    }
    case 21:
    {
        delphi::objects::ppappa1intbndl1metrics_t *reg = &ppappa1intbndl1metrics;
        switch (field_id) {
        case 2:
            reg->state_lkp_srch_hit_addr_range_err++;
            break;
        case 3:
            reg->state_lkp_srch_miss++;
            break;
        case 4:
            reg->state_lkp_srch_req_not_rdy++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intbndl1Metrics::Publish(key, reg);
        break;
    }
    case 22:
    {
        delphi::objects::ppappa1inteccmetrics_t *reg = &ppappa1inteccmetrics;
        switch (field_id) {
        case 2:
            reg->pkt_mem_uncorrectable++;
            break;
        case 3:
            reg->pkt_mem_correctable++;
            break;
        case 4:
            reg->bndl0_state_lkp_sram_uncorrectable++;
            break;
        case 5:
            reg->bndl0_state_lkp_sram_correctable++;
            break;
        case 6:
            reg->bndl1_state_lkp_sram_uncorrectable++;
            break;
        case 7:
            reg->bndl1_state_lkp_sram_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1inteccMetrics::Publish(key, reg);
        break;
    }
    case 23:
    {
        delphi::objects::ppappa1intfifo1metrics_t *reg = &ppappa1intfifo1metrics;
        switch (field_id) {
        case 2:
            reg->pe0_qctl_ff_ovflow++;
            break;
        case 3:
            reg->pe1_qctl_ff_ovflow++;
            break;
        case 4:
            reg->pe2_qctl_ff_ovflow++;
            break;
        case 5:
            reg->pe3_qctl_ff_ovflow++;
            break;
        case 6:
            reg->pe4_qctl_ff_ovflow++;
            break;
        case 7:
            reg->pe5_qctl_ff_ovflow++;
            break;
        case 8:
            reg->pe6_qctl_ff_ovflow++;
            break;
        case 9:
            reg->pe7_qctl_ff_ovflow++;
            break;
        case 10:
            reg->pe8_qctl_ff_ovflow++;
            break;
        case 11:
            reg->pe9_qctl_ff_ovflow++;
            break;
        case 12:
            reg->pe0_phv_ff_ovflow++;
            break;
        case 13:
            reg->pe1_phv_ff_ovflow++;
            break;
        case 14:
            reg->pe2_phv_ff_ovflow++;
            break;
        case 15:
            reg->pe3_phv_ff_ovflow++;
            break;
        case 16:
            reg->pe4_phv_ff_ovflow++;
            break;
        case 17:
            reg->pe5_phv_ff_ovflow++;
            break;
        case 18:
            reg->pe6_phv_ff_ovflow++;
            break;
        case 19:
            reg->pe7_phv_ff_ovflow++;
            break;
        case 20:
            reg->pe8_phv_ff_ovflow++;
            break;
        case 21:
            reg->pe9_phv_ff_ovflow++;
            break;
        case 22:
            reg->pe0_ohi_ff_ovflow++;
            break;
        case 23:
            reg->pe1_ohi_ff_ovflow++;
            break;
        case 24:
            reg->pe2_ohi_ff_ovflow++;
            break;
        case 25:
            reg->pe3_ohi_ff_ovflow++;
            break;
        case 26:
            reg->pe4_ohi_ff_ovflow++;
            break;
        case 27:
            reg->pe5_ohi_ff_ovflow++;
            break;
        case 28:
            reg->pe6_ohi_ff_ovflow++;
            break;
        case 29:
            reg->pe7_ohi_ff_ovflow++;
            break;
        case 30:
            reg->pe8_ohi_ff_ovflow++;
            break;
        case 31:
            reg->pe9_ohi_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intfifo1Metrics::Publish(key, reg);
        break;
    }
    case 24:
    {
        delphi::objects::ppappa1intfifo2metrics_t *reg = &ppappa1intfifo2metrics;
        switch (field_id) {
        case 2:
            reg->dp_if_ff_ovflow++;
            break;
        case 3:
            reg->ohi_if_ff_ovflow++;
            break;
        case 4:
            reg->ma_if_ff_ovflow++;
            break;
        case 5:
            reg->pb_if_ff_ovflow++;
            break;
        case 6:
            reg->pkt_mtu_ff_ovflow++;
            break;
        case 7:
            reg->outphv_ff_ovflow++;
            break;
        case 8:
            reg->outohi_ff_ovflow++;
            break;
        case 9:
            reg->chk_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intfifo2Metrics::Publish(key, reg);
        break;
    }
    case 25:
    {
        delphi::objects::ppappa1intpe0metrics_t *reg = &ppappa1intpe0metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe0Metrics::Publish(key, reg);
        break;
    }
    case 26:
    {
        delphi::objects::ppappa1intpe1metrics_t *reg = &ppappa1intpe1metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe1Metrics::Publish(key, reg);
        break;
    }
    case 27:
    {
        delphi::objects::ppappa1intpe2metrics_t *reg = &ppappa1intpe2metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe2Metrics::Publish(key, reg);
        break;
    }
    case 28:
    {
        delphi::objects::ppappa1intpe3metrics_t *reg = &ppappa1intpe3metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe3Metrics::Publish(key, reg);
        break;
    }
    case 29:
    {
        delphi::objects::ppappa1intpe4metrics_t *reg = &ppappa1intpe4metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe4Metrics::Publish(key, reg);
        break;
    }
    case 30:
    {
        delphi::objects::ppappa1intpe5metrics_t *reg = &ppappa1intpe5metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe5Metrics::Publish(key, reg);
        break;
    }
    case 31:
    {
        delphi::objects::ppappa1intpe6metrics_t *reg = &ppappa1intpe6metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe6Metrics::Publish(key, reg);
        break;
    }
    case 32:
    {
        delphi::objects::ppappa1intpe7metrics_t *reg = &ppappa1intpe7metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe7Metrics::Publish(key, reg);
        break;
    }
    case 33:
    {
        delphi::objects::ppappa1intpe8metrics_t *reg = &ppappa1intpe8metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe8Metrics::Publish(key, reg);
        break;
    }
    case 34:
    {
        delphi::objects::ppappa1intpe9metrics_t *reg = &ppappa1intpe9metrics;
        switch (field_id) {
        case 2:
            reg->qctl_skid_depth_not_zero++;
            break;
        case 3:
            reg->qctl_not_sop_after_pkt_release++;
            break;
        case 4:
            reg->unexpected_non_sop++;
            break;
        case 5:
            reg->exceed_phv_flit_cnt++;
            break;
        case 6:
            reg->exceed_parse_loop_cnt++;
            break;
        case 7:
            reg->offset_out_of_range++;
            break;
        case 8:
            reg->pkt_size_chk++;
            break;
        case 9:
            reg->offset_jump_chk++;
            break;
        case 10:
            reg->d1_not_valid++;
            break;
        case 11:
            reg->phv_upr_idx_less++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpe9Metrics::Publish(key, reg);
        break;
    }
    case 35:
    {
        delphi::objects::ppappa1intpametrics_t *reg = &ppappa1intpametrics;
        switch (field_id) {
        case 2:
            reg->reorder_phv_not_sop++;
            break;
        case 3:
            reg->csum0_not_enuf_bytes++;
            break;
        case 4:
            reg->csum0_start_more_than_end_offset++;
            break;
        case 5:
            reg->csum1_not_enuf_bytes++;
            break;
        case 6:
            reg->csum1_start_more_than_end_offset++;
            break;
        case 7:
            reg->csum2_not_enuf_bytes++;
            break;
        case 8:
            reg->csum2_start_more_than_end_offset++;
            break;
        case 9:
            reg->csum3_not_enuf_bytes++;
            break;
        case 10:
            reg->csum3_start_more_than_end_offset++;
            break;
        case 11:
            reg->csum4_not_enuf_bytes++;
            break;
        case 12:
            reg->csum4_start_more_than_end_offset++;
            break;
        case 13:
            reg->crc_not_enuf_bytes++;
            break;
        case 14:
            reg->crc_start_more_than_end_offset++;
            break;
        case 15:
            reg->chkr_phv_single_flit++;
            break;
        case 16:
            reg->chkr_phv_not_sop++;
            break;
        case 17:
            reg->chkr_pkt_not_sop++;
            break;
        case 18:
            reg->chkr_seq_id++;
            break;
        case 19:
            reg->preparse_line0_not_sop++;
            break;
        case 20:
            reg->preparse_dff_not_sop++;
            break;
        case 21:
            reg->preparse_dff_ovflow++;
            break;
        case 22:
            reg->preparse_eff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intpaMetrics::Publish(key, reg);
        break;
    }
    case 36:
    {
        delphi::objects::ppappa1intswphvmemmetrics_t *reg = &ppappa1intswphvmemmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_uncorrectable++;
            break;
        case 3:
            reg->ecc_correctable++;
            break;
        case 4:
            reg->phv_invalid_sram++;
            break;
        case 5:
            reg->phv_invalid_data++;
            break;
        case 6:
            reg->phv_done0++;
            break;
        case 7:
            reg->phv_done1++;
            break;
        case 8:
            reg->phv_done2++;
            break;
        case 9:
            reg->phv_done3++;
            break;
        case 10:
            reg->phv_done4++;
            break;
        case 11:
            reg->phv_done5++;
            break;
        case 12:
            reg->phv_done6++;
            break;
        case 13:
            reg->phv_done7++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intswphvmemMetrics::Publish(key, reg);
        break;
    }
    case 37:
    {
        delphi::objects::ppappa1intintfmetrics_t *reg = &ppappa1intintfmetrics;
        switch (field_id) {
        case 2:
            reg->pb_err++;
            break;
        case 3:
            reg->pb_sop_err++;
            break;
        case 4:
            reg->pb_eop_err++;
            break;
        case 5:
            reg->dp_err++;
            break;
        case 6:
            reg->dp_sop_err++;
            break;
        case 7:
            reg->dp_eop_err++;
            break;
        case 8:
            reg->ohi_err++;
            break;
        case 9:
            reg->ohi_sop_err++;
            break;
        case 10:
            reg->ohi_eop_err++;
            break;
        case 11:
            reg->sw_phv_err++;
            break;
        case 12:
            reg->sw_phv_sop_err++;
            break;
        case 13:
            reg->sw_phv_eop_err++;
            break;
        case 14:
            reg->ma_err++;
            break;
        case 15:
            reg->ma_sop_err++;
            break;
        case 16:
            reg->ma_eop_err++;
            break;
        default:
            break;
        }
        delphi::objects::Ppappa1intintfMetrics::Publish(key, reg);
        break;
    }
    case 39:
    {
        delphi::objects::sgite0interrmetrics_t *reg = &sgite0interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite0interrMetrics::Publish(key, reg);
        break;
    }
    case 40:
    {
        delphi::objects::sgite0intinfometrics_t *reg = &sgite0intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite0intinfoMetrics::Publish(key, reg);
        break;
    }
    case 42:
    {
        delphi::objects::sgite1interrmetrics_t *reg = &sgite1interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite1interrMetrics::Publish(key, reg);
        break;
    }
    case 43:
    {
        delphi::objects::sgite1intinfometrics_t *reg = &sgite1intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite1intinfoMetrics::Publish(key, reg);
        break;
    }
    case 45:
    {
        delphi::objects::sgite2interrmetrics_t *reg = &sgite2interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite2interrMetrics::Publish(key, reg);
        break;
    }
    case 46:
    {
        delphi::objects::sgite2intinfometrics_t *reg = &sgite2intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite2intinfoMetrics::Publish(key, reg);
        break;
    }
    case 48:
    {
        delphi::objects::sgite3interrmetrics_t *reg = &sgite3interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite3interrMetrics::Publish(key, reg);
        break;
    }
    case 49:
    {
        delphi::objects::sgite3intinfometrics_t *reg = &sgite3intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite3intinfoMetrics::Publish(key, reg);
        break;
    }
    case 51:
    {
        delphi::objects::sgite4interrmetrics_t *reg = &sgite4interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite4interrMetrics::Publish(key, reg);
        break;
    }
    case 52:
    {
        delphi::objects::sgite4intinfometrics_t *reg = &sgite4intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite4intinfoMetrics::Publish(key, reg);
        break;
    }
    case 54:
    {
        delphi::objects::sgite5interrmetrics_t *reg = &sgite5interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite5interrMetrics::Publish(key, reg);
        break;
    }
    case 55:
    {
        delphi::objects::sgite5intinfometrics_t *reg = &sgite5intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgite5intinfoMetrics::Publish(key, reg);
        break;
    }
    case 57:
    {
        delphi::objects::sgimpu0interrmetrics_t *reg = &sgimpu0interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu0interrMetrics::Publish(key, reg);
        break;
    }
    case 58:
    {
        delphi::objects::sgimpu0intinfometrics_t *reg = &sgimpu0intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu0intinfoMetrics::Publish(key, reg);
        break;
    }
    case 60:
    {
        delphi::objects::sgimpu1interrmetrics_t *reg = &sgimpu1interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu1interrMetrics::Publish(key, reg);
        break;
    }
    case 61:
    {
        delphi::objects::sgimpu1intinfometrics_t *reg = &sgimpu1intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu1intinfoMetrics::Publish(key, reg);
        break;
    }
    case 63:
    {
        delphi::objects::sgimpu2interrmetrics_t *reg = &sgimpu2interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu2interrMetrics::Publish(key, reg);
        break;
    }
    case 64:
    {
        delphi::objects::sgimpu2intinfometrics_t *reg = &sgimpu2intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu2intinfoMetrics::Publish(key, reg);
        break;
    }
    case 66:
    {
        delphi::objects::sgimpu3interrmetrics_t *reg = &sgimpu3interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu3interrMetrics::Publish(key, reg);
        break;
    }
    case 67:
    {
        delphi::objects::sgimpu3intinfometrics_t *reg = &sgimpu3intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu3intinfoMetrics::Publish(key, reg);
        break;
    }
    case 69:
    {
        delphi::objects::sgimpu4interrmetrics_t *reg = &sgimpu4interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu4interrMetrics::Publish(key, reg);
        break;
    }
    case 70:
    {
        delphi::objects::sgimpu4intinfometrics_t *reg = &sgimpu4intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu4intinfoMetrics::Publish(key, reg);
        break;
    }
    case 72:
    {
        delphi::objects::sgimpu5interrmetrics_t *reg = &sgimpu5interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu5interrMetrics::Publish(key, reg);
        break;
    }
    case 73:
    {
        delphi::objects::sgimpu5intinfometrics_t *reg = &sgimpu5intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgimpu5intinfoMetrics::Publish(key, reg);
        break;
    }
    case 75:
    {
        delphi::objects::rpcpicsintpicsmetrics_t *reg = &rpcpicsintpicsmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable_ecc++;
            break;
        case 3:
            reg->correctable_ecc++;
            break;
        case 4:
            reg->too_many_rl_sch_error++;
            break;
        case 5:
            reg->picc++;
            break;
        default:
            break;
        }
        delphi::objects::RpcpicsintpicsMetrics::Publish(key, reg);
        break;
    }
    case 76:
    {
        delphi::objects::rpcpicsintbadaddrmetrics_t *reg = &rpcpicsintbadaddrmetrics;
        switch (field_id) {
        case 2:
            reg->rdreq0_bad_addr++;
            break;
        case 3:
            reg->wrreq0_bad_addr++;
            break;
        case 4:
            reg->rdreq1_bad_addr++;
            break;
        case 5:
            reg->wrreq1_bad_addr++;
            break;
        case 6:
            reg->rdreq2_bad_addr++;
            break;
        case 7:
            reg->wrreq2_bad_addr++;
            break;
        case 8:
            reg->rdreq3_bad_addr++;
            break;
        case 9:
            reg->wrreq3_bad_addr++;
            break;
        case 10:
            reg->rdreq4_bad_addr++;
            break;
        case 11:
            reg->wrreq4_bad_addr++;
            break;
        case 12:
            reg->rdreq5_bad_addr++;
            break;
        case 13:
            reg->wrreq5_bad_addr++;
            break;
        case 14:
            reg->rdreq6_bad_addr++;
            break;
        case 15:
            reg->wrreq6_bad_addr++;
            break;
        case 16:
            reg->rdreq7_bad_addr++;
            break;
        case 17:
            reg->wrreq7_bad_addr++;
            break;
        case 18:
            reg->cpu_bad_addr++;
            break;
        case 19:
            reg->bg_bad_addr++;
            break;
        default:
            break;
        }
        delphi::objects::RpcpicsintbadaddrMetrics::Publish(key, reg);
        break;
    }
    case 77:
    {
        delphi::objects::rpcpicsintbgmetrics_t *reg = &rpcpicsintbgmetrics;
        switch (field_id) {
        case 2:
            reg->unfinished_bg0++;
            break;
        case 3:
            reg->unfinished_bg1++;
            break;
        case 4:
            reg->unfinished_bg2++;
            break;
        case 5:
            reg->unfinished_bg3++;
            break;
        case 6:
            reg->unfinished_bg4++;
            break;
        case 7:
            reg->unfinished_bg5++;
            break;
        case 8:
            reg->unfinished_bg6++;
            break;
        case 9:
            reg->unfinished_bg7++;
            break;
        case 10:
            reg->unfinished_bg8++;
            break;
        case 11:
            reg->unfinished_bg9++;
            break;
        case 12:
            reg->unfinished_bg10++;
            break;
        case 13:
            reg->unfinished_bg11++;
            break;
        case 14:
            reg->unfinished_bg12++;
            break;
        case 15:
            reg->unfinished_bg13++;
            break;
        case 16:
            reg->unfinished_bg14++;
            break;
        case 17:
            reg->unfinished_bg15++;
            break;
        default:
            break;
        }
        delphi::objects::RpcpicsintbgMetrics::Publish(key, reg);
        break;
    }
    case 79:
    {
        delphi::objects::rpcpicspiccintpiccmetrics_t *reg = &rpcpicspiccintpiccmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable_ecc++;
            break;
        case 3:
            reg->correctable_ecc++;
            break;
        case 4:
            reg->cache_stg_awlen_err++;
            break;
        case 5:
            reg->cache_hbm_rresp_slverr++;
            break;
        case 6:
            reg->cache_hbm_rresp_decerr++;
            break;
        case 7:
            reg->cache_hbm_bresp_slverr++;
            break;
        case 8:
            reg->cache_hbm_bresp_decerr++;
            break;
        default:
            break;
        }
        delphi::objects::RpcpicspiccintpiccMetrics::Publish(key, reg);
        break;
    }
    case 81:
    {
        delphi::objects::intrintrintintreccmetrics_t *reg = &intrintrintintreccmetrics;
        switch (field_id) {
        case 2:
            reg->intr_state_uncorrectable++;
            break;
        case 3:
            reg->intr_state_correctable++;
            break;
        case 4:
            reg->intr_pba_cfg_uncorrectable++;
            break;
        case 5:
            reg->intr_pba_cfg_correctable++;
            break;
        case 6:
            reg->intr_coalesce_uncorrectable++;
            break;
        case 7:
            reg->intr_coalesce_correctable++;
            break;
        case 8:
            reg->intr_legacy_fifo_overrun++;
            break;
        case 9:
            reg->int_credit_positive_after_return_interrupt++;
            break;
        case 10:
            reg->int_credits_max_debug_threshold_interrupt++;
            break;
        case 11:
            reg->intr_bresp_err++;
            break;
        default:
            break;
        }
        delphi::objects::IntrintrintintreccMetrics::Publish(key, reg);
        break;
    }
    case 83:
    {
        delphi::objects::pxbpxbinttgteccmetrics_t *reg = &pxbpxbinttgteccmetrics;
        switch (field_id) {
        case 2:
            reg->aximst_0_uncorrectable++;
            break;
        case 3:
            reg->aximst_0_correctable++;
            break;
        case 4:
            reg->aximst_1_uncorrectable++;
            break;
        case 5:
            reg->aximst_1_correctable++;
            break;
        case 6:
            reg->aximst_2_uncorrectable++;
            break;
        case 7:
            reg->aximst_2_correctable++;
            break;
        case 8:
            reg->aximst_3_uncorrectable++;
            break;
        case 9:
            reg->aximst_3_correctable++;
            break;
        case 10:
            reg->aximst_4_uncorrectable++;
            break;
        case 11:
            reg->aximst_4_correctable++;
            break;
        case 12:
            reg->rxcrbfr_0_uncorrectable++;
            break;
        case 13:
            reg->rxcrbfr_0_correctable++;
            break;
        case 14:
            reg->rxcrbfr_1_uncorrectable++;
            break;
        case 15:
            reg->rxcrbfr_1_correctable++;
            break;
        case 16:
            reg->rxcrbfr_2_uncorrectable++;
            break;
        case 17:
            reg->rxcrbfr_2_correctable++;
            break;
        case 18:
            reg->rxcrbfr_3_uncorrectable++;
            break;
        case 19:
            reg->rxcrbfr_3_correctable++;
            break;
        case 20:
            reg->rxinfo_uncorrectable++;
            break;
        case 21:
            reg->rxinfo_correctable++;
            break;
        case 22:
            reg->cplst_uncorrectable++;
            break;
        case 23:
            reg->cplst_correctable++;
            break;
        case 24:
            reg->romask_uncorrectable++;
            break;
        case 25:
            reg->romask_correctable++;
            break;
        case 26:
            reg->pmr_uncorrectable++;
            break;
        case 27:
            reg->pmr_correctable++;
            break;
        case 28:
            reg->prt_uncorrectable++;
            break;
        case 29:
            reg->prt_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PxbpxbinttgteccMetrics::Publish(key, reg);
        break;
    }
    case 84:
    {
        delphi::objects::pxbpxbintitreccmetrics_t *reg = &pxbpxbintitreccmetrics;
        switch (field_id) {
        case 2:
            reg->pcihdrt_uncorrectable++;
            break;
        case 3:
            reg->pcihdrt_correctable++;
            break;
        case 4:
            reg->portmap_uncorrectable++;
            break;
        case 5:
            reg->portmap_correctable++;
            break;
        case 6:
            reg->wrhdr_uncorrectable++;
            break;
        case 7:
            reg->wrhdr_correctable++;
            break;
        case 8:
            reg->rdhdr_uncorrectable++;
            break;
        case 9:
            reg->rdhdr_correctable++;
            break;
        case 10:
            reg->wrbfr_0_uncorrectable++;
            break;
        case 11:
            reg->wrbfr_0_correctable++;
            break;
        case 12:
            reg->wrbfr_1_uncorrectable++;
            break;
        case 13:
            reg->wrbfr_1_correctable++;
            break;
        case 14:
            reg->wrbfr_2_uncorrectable++;
            break;
        case 15:
            reg->wrbfr_2_correctable++;
            break;
        case 16:
            reg->wrbfr_3_uncorrectable++;
            break;
        case 17:
            reg->wrbfr_3_correctable++;
            break;
        case 18:
            reg->cplbfr_uncorrectable++;
            break;
        case 19:
            reg->cplbfr_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PxbpxbintitreccMetrics::Publish(key, reg);
        break;
    }
    case 85:
    {
        delphi::objects::pxbpxbinterrmetrics_t *reg = &pxbpxbinterrmetrics;
        switch (field_id) {
        case 2:
            reg->cpl_ecrc++;
            break;
        case 3:
            reg->cpl_rxbuf_err++;
            break;
        case 4:
            reg->cpl_stat++;
            break;
        case 5:
            reg->cpl_unexp++;
            break;
        case 6:
            reg->cpl_timeout++;
            break;
        case 7:
            reg->cpl_len++;
            break;
        case 8:
            reg->cpl_poison++;
            break;
        case 9:
            reg->cpl_lowaddr++;
            break;
        case 10:
            reg->tgt_ind_rsp_unexp++;
            break;
        case 11:
            reg->tgt_axi_rsp_unexp++;
            break;
        case 12:
            reg->tgt_axi_rsp_err++;
            break;
        case 13:
            reg->tgt_req_4k_err++;
            break;
        case 14:
            reg->itr_req_bdfmiss++;
            break;
        case 15:
            reg->itr_req_axi_unsupp++;
            break;
        case 16:
            reg->itr_req_msg_align_err++;
            break;
        case 17:
            reg->itr_bus_master_dis++;
            break;
        case 18:
            reg->itr_atomic_seq_err++;
            break;
        case 19:
            reg->itr_atomic_resource_err++;
            break;
        case 20:
            reg->tgt_rmw_axi_resperr++;
            break;
        case 21:
            reg->tgt_ind_notify_axi_resperr++;
            break;
        default:
            break;
        }
        delphi::objects::PxbpxbinterrMetrics::Publish(key, reg);
        break;
    }
    case 87:
    {
        delphi::objects::sgete0interrmetrics_t *reg = &sgete0interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete0interrMetrics::Publish(key, reg);
        break;
    }
    case 88:
    {
        delphi::objects::sgete0intinfometrics_t *reg = &sgete0intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete0intinfoMetrics::Publish(key, reg);
        break;
    }
    case 90:
    {
        delphi::objects::sgete1interrmetrics_t *reg = &sgete1interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete1interrMetrics::Publish(key, reg);
        break;
    }
    case 91:
    {
        delphi::objects::sgete1intinfometrics_t *reg = &sgete1intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete1intinfoMetrics::Publish(key, reg);
        break;
    }
    case 93:
    {
        delphi::objects::sgete2interrmetrics_t *reg = &sgete2interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete2interrMetrics::Publish(key, reg);
        break;
    }
    case 94:
    {
        delphi::objects::sgete2intinfometrics_t *reg = &sgete2intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete2intinfoMetrics::Publish(key, reg);
        break;
    }
    case 96:
    {
        delphi::objects::sgete3interrmetrics_t *reg = &sgete3interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete3interrMetrics::Publish(key, reg);
        break;
    }
    case 97:
    {
        delphi::objects::sgete3intinfometrics_t *reg = &sgete3intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete3intinfoMetrics::Publish(key, reg);
        break;
    }
    case 99:
    {
        delphi::objects::sgete4interrmetrics_t *reg = &sgete4interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete4interrMetrics::Publish(key, reg);
        break;
    }
    case 100:
    {
        delphi::objects::sgete4intinfometrics_t *reg = &sgete4intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete4intinfoMetrics::Publish(key, reg);
        break;
    }
    case 102:
    {
        delphi::objects::sgete5interrmetrics_t *reg = &sgete5interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete5interrMetrics::Publish(key, reg);
        break;
    }
    case 103:
    {
        delphi::objects::sgete5intinfometrics_t *reg = &sgete5intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Sgete5intinfoMetrics::Publish(key, reg);
        break;
    }
    case 105:
    {
        delphi::objects::sgempu0interrmetrics_t *reg = &sgempu0interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu0interrMetrics::Publish(key, reg);
        break;
    }
    case 106:
    {
        delphi::objects::sgempu0intinfometrics_t *reg = &sgempu0intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu0intinfoMetrics::Publish(key, reg);
        break;
    }
    case 108:
    {
        delphi::objects::sgempu1interrmetrics_t *reg = &sgempu1interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu1interrMetrics::Publish(key, reg);
        break;
    }
    case 109:
    {
        delphi::objects::sgempu1intinfometrics_t *reg = &sgempu1intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu1intinfoMetrics::Publish(key, reg);
        break;
    }
    case 111:
    {
        delphi::objects::sgempu2interrmetrics_t *reg = &sgempu2interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu2interrMetrics::Publish(key, reg);
        break;
    }
    case 112:
    {
        delphi::objects::sgempu2intinfometrics_t *reg = &sgempu2intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu2intinfoMetrics::Publish(key, reg);
        break;
    }
    case 114:
    {
        delphi::objects::sgempu3interrmetrics_t *reg = &sgempu3interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu3interrMetrics::Publish(key, reg);
        break;
    }
    case 115:
    {
        delphi::objects::sgempu3intinfometrics_t *reg = &sgempu3intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu3intinfoMetrics::Publish(key, reg);
        break;
    }
    case 117:
    {
        delphi::objects::sgempu4interrmetrics_t *reg = &sgempu4interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu4interrMetrics::Publish(key, reg);
        break;
    }
    case 118:
    {
        delphi::objects::sgempu4intinfometrics_t *reg = &sgempu4intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu4intinfoMetrics::Publish(key, reg);
        break;
    }
    case 120:
    {
        delphi::objects::sgempu5interrmetrics_t *reg = &sgempu5interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu5interrMetrics::Publish(key, reg);
        break;
    }
    case 121:
    {
        delphi::objects::sgempu5intinfometrics_t *reg = &sgempu5intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Sgempu5intinfoMetrics::Publish(key, reg);
        break;
    }
    case 123:
    {
        delphi::objects::prprintreg1metrics_t *reg = &prprintreg1metrics;
        switch (field_id) {
        case 2:
            reg->slave_prd++;
            break;
        case 3:
            reg->slave_psp++;
            break;
        default:
            break;
        }
        delphi::objects::Prprintreg1Metrics::Publish(key, reg);
        break;
    }
    case 125:
    {
        delphi::objects::prprpspintinfometrics_t *reg = &prprpspintinfometrics;
        switch (field_id) {
        case 2:
            reg->pr_pkt_ff_almost_full++;
            break;
        case 3:
            reg->ptd_npv_phv_full++;
            break;
        case 4:
            reg->phv_srdy_collapsed++;
            break;
        case 5:
            reg->pr_resub_pkt_before_phv++;
            break;
        case 6:
            reg->pb_pbus_fsm0_no_data++;
            break;
        case 7:
            reg->pb_pbus_fsm1_no_data++;
            break;
        case 8:
            reg->pb_pbus_fsm2_no_data++;
            break;
        case 9:
            reg->pb_pbus_fsm3_no_data++;
            break;
        case 10:
            reg->pb_pbus_fsm4_no_data++;
            break;
        default:
            break;
        }
        delphi::objects::PrprpspintinfoMetrics::Publish(key, reg);
        break;
    }
    case 126:
    {
        delphi::objects::prprpspinterrmetrics_t *reg = &prprpspinterrmetrics;
        switch (field_id) {
        case 2:
            reg->pb_pbus_err++;
            break;
        case 3:
            reg->pr_pbus_err++;
            break;
        case 4:
            reg->pr_resub_pbus_err++;
            break;
        case 5:
            reg->psp_csr_read_access_err++;
            break;
        case 6:
            reg->psp_csr_write_access_err++;
            break;
        case 7:
            reg->psp_phv_larger_than_twelve_flits_err++;
            break;
        case 8:
            reg->psp_phv_sop_offset_err++;
            break;
        case 9:
            reg->psp_phv_eop_offset_err++;
            break;
        case 10:
            reg->max_recir_count_err++;
            break;
        case 11:
            reg->pb_pbus_dummy_err++;
            break;
        case 12:
            reg->pb_pbus_nopkt_err++;
            break;
        case 13:
            reg->pb_pbus_min_err++;
            break;
        case 14:
            reg->lb_phv_almost_full_timeout_err++;
            break;
        case 15:
            reg->lb_pkt_almost_full_timeout_err++;
            break;
        default:
            break;
        }
        delphi::objects::PrprpspinterrMetrics::Publish(key, reg);
        break;
    }
    case 127:
    {
        delphi::objects::prprpspintfatalmetrics_t *reg = &prprpspintfatalmetrics;
        switch (field_id) {
        case 2:
            reg->pb_pbus_sop_err++;
            break;
        case 3:
            reg->pb_pbus_eop_err++;
            break;
        case 4:
            reg->ma_sop_err++;
            break;
        case 5:
            reg->ma_eop_err++;
            break;
        case 6:
            reg->pr_pbus_sop_err++;
            break;
        case 7:
            reg->pr_pbus_eop_err++;
            break;
        case 8:
            reg->pr_resub_pbus_sop_err++;
            break;
        case 9:
            reg->pr_resub_pbus_eop_err++;
            break;
        case 10:
            reg->pr_resub_sop_err++;
            break;
        case 11:
            reg->pr_resub_eop_err++;
            break;
        case 12:
            reg->pb_pbus_fsm0_no_data_err++;
            break;
        case 13:
            reg->pb_pbus_fsm1_no_data_err++;
            break;
        case 14:
            reg->pb_pbus_fsm2_no_data_err++;
            break;
        case 15:
            reg->pb_pbus_fsm3_no_data_err++;
            break;
        case 16:
            reg->pb_pbus_fsm4_no_data_err++;
            break;
        case 17:
            reg->pb_pbus_fsm5_pkt_too_small_err++;
            break;
        case 18:
            reg->lif_ind_table_rsp_err++;
            break;
        case 19:
            reg->flit_cnt_oflow_err++;
            break;
        case 20:
            reg->lb_phv_sop_err++;
            break;
        case 21:
            reg->dc_phv_sop_err++;
            break;
        case 22:
            reg->lb_pkt_sop_err++;
            break;
        case 23:
            reg->dc_pkt_sop_err++;
            break;
        case 24:
            reg->sw_phv_jabber_err++;
            break;
        default:
            break;
        }
        delphi::objects::PrprpspintfatalMetrics::Publish(key, reg);
        break;
    }
    case 128:
    {
        delphi::objects::prprpspintlifqstatemapmetrics_t *reg = &prprpspintlifqstatemapmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_uncorrectable++;
            break;
        case 3:
            reg->ecc_correctable++;
            break;
        case 4:
            reg->qid_invalid++;
            break;
        default:
            break;
        }
        delphi::objects::PrprpspintlifqstatemapMetrics::Publish(key, reg);
        break;
    }
    case 129:
    {
        delphi::objects::prprpspintswphvmemmetrics_t *reg = &prprpspintswphvmemmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_uncorrectable++;
            break;
        case 3:
            reg->ecc_correctable++;
            break;
        case 4:
            reg->phv_invalid_sram++;
            break;
        case 5:
            reg->phv_invalid_data++;
            break;
        case 6:
            reg->phv_done0++;
            break;
        case 7:
            reg->phv_done1++;
            break;
        case 8:
            reg->phv_done2++;
            break;
        case 9:
            reg->phv_done3++;
            break;
        case 10:
            reg->phv_done4++;
            break;
        case 11:
            reg->phv_done5++;
            break;
        case 12:
            reg->phv_done6++;
            break;
        case 13:
            reg->phv_done7++;
            break;
        default:
            break;
        }
        delphi::objects::PrprpspintswphvmemMetrics::Publish(key, reg);
        break;
    }
    case 131:
    {
        delphi::objects::prprprdinteccmetrics_t *reg = &prprprdinteccmetrics;
        switch (field_id) {
        case 2:
            reg->rdata_mem_uncorrectable++;
            break;
        case 3:
            reg->rdata_mem_correctable++;
            break;
        case 4:
            reg->pkt_mem_uncorrectable++;
            break;
        case 5:
            reg->pkt_mem_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PrprprdinteccMetrics::Publish(key, reg);
        break;
    }
    case 132:
    {
        delphi::objects::prprprdintfifometrics_t *reg = &prprprdintfifometrics;
        switch (field_id) {
        case 2:
            reg->wr_lat_ff_ovflow++;
            break;
        case 3:
            reg->rd_lat_ff_ovflow++;
            break;
        case 4:
            reg->wdata_ff_ovflow++;
            break;
        case 5:
            reg->rcv_stg_ff_ovflow++;
            break;
        case 6:
            reg->cmdflit_ff_ovflow++;
            break;
        case 7:
            reg->cmd_ff_ovflow++;
            break;
        case 8:
            reg->pkt_ff_ovflow++;
            break;
        case 9:
            reg->pkt_order_ff_ovflow++;
            break;
        case 10:
            reg->pkt_stg_ff_ovflow++;
            break;
        case 11:
            reg->wr_mem_ff_ovflow++;
            break;
        case 12:
            reg->dfence_ff_ovflow++;
            break;
        case 13:
            reg->ffence_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::PrprprdintfifoMetrics::Publish(key, reg);
        break;
    }
    case 133:
    {
        delphi::objects::prprprdintgrp1metrics_t *reg = &prprprdintgrp1metrics;
        switch (field_id) {
        case 2:
            reg->rcv_phv_dma_ptr++;
            break;
        case 3:
            reg->rcv_phv_addr++;
            break;
        case 4:
            reg->rcv_exceed_16byte++;
            break;
        case 5:
            reg->rcv_phv_not_sop++;
            break;
        case 6:
            reg->rcv_pkt_order_ff_full++;
            break;
        case 7:
            reg->rcv_pend_phv_more_than_2++;
            break;
        case 8:
            reg->rcv_pend_phv_less++;
            break;
        case 9:
            reg->rcv_cmd_nop_eop++;
            break;
        case 10:
            reg->rcv_cmd_out_not_sop++;
            break;
        case 11:
            reg->rcv_no_data_but_pkt2mem_cmd++;
            break;
        case 12:
            reg->rcv_no_data_but_skip_cmd++;
            break;
        case 13:
            reg->rcv_mem2pkt_seen++;
            break;
        case 14:
            reg->rcv_phv2pkt_seen++;
            break;
        case 15:
            reg->rcv_phv_eop_no_cmd_eop++;
            break;
        case 16:
            reg->rcv_m2m_dst_not_seen++;
            break;
        case 17:
            reg->rcv_m2m_src_not_seen++;
            break;
        case 18:
            reg->rdreq_invalid_cmd_seen++;
            break;
        case 19:
            reg->rdreq_mem2mem_psize_zero++;
            break;
        case 20:
            reg->rdreq_m2m_phv2mem_exceed_16byte++;
            break;
        case 21:
            reg->rdreq_phv2mem_fence_exceed_16byte++;
            break;
        case 22:
            reg->rdreq_pkt2mem_psize_zero++;
            break;
        case 23:
            reg->rdreq_skip_psize_zero++;
            break;
        default:
            break;
        }
        delphi::objects::Prprprdintgrp1Metrics::Publish(key, reg);
        break;
    }
    case 134:
    {
        delphi::objects::prprprdintgrp2metrics_t *reg = &prprprdintgrp2metrics;
        switch (field_id) {
        case 2:
            reg->wr_axi_rd_err_recovery++;
            break;
        case 3:
            reg->wr_axi_rd_resp++;
            break;
        case 4:
            reg->wr_not_enuf_pkt_bytes++;
            break;
        case 5:
            reg->wr_invalid_cmd++;
            break;
        case 6:
            reg->wr_seq_id++;
            break;
        case 7:
            reg->wr_no_data_pkt_cmd++;
            break;
        case 8:
            reg->rdrsp_axi++;
            break;
        case 9:
            reg->wrrsp_axi++;
            break;
        case 10:
            reg->pkt_not_sop++;
            break;
        case 11:
            reg->pkt_len_calc_len_mismatch++;
            break;
        case 12:
            reg->spurious_rd_resp++;
            break;
        case 13:
            reg->rdrsp_axi_id_out_of_range++;
            break;
        case 14:
            reg->spurious_wr_resp++;
            break;
        case 15:
            reg->wrreq_info_first_missing++;
            break;
        case 16:
            reg->wrreq_num_bytes_zero++;
            break;
        case 17:
            reg->wrreq_num_bytes_more_than_64++;
            break;
        default:
            break;
        }
        delphi::objects::Prprprdintgrp2Metrics::Publish(key, reg);
        break;
    }
    case 135:
    {
        delphi::objects::prprprdintintfmetrics_t *reg = &prprprdintintfmetrics;
        switch (field_id) {
        case 2:
            reg->ps_pkt_err++;
            break;
        case 3:
            reg->ps_pkt_sop_err++;
            break;
        case 4:
            reg->ps_pkt_eop_err++;
            break;
        case 5:
            reg->ps_resub_pkt_err++;
            break;
        case 6:
            reg->ps_resub_pkt_sop_err++;
            break;
        case 7:
            reg->ps_resub_pkt_eop_err++;
            break;
        case 8:
            reg->ps_resub_phv_err++;
            break;
        case 9:
            reg->ps_resub_phv_sop_err++;
            break;
        case 10:
            reg->ps_resub_phv_eop_err++;
            break;
        case 11:
            reg->ma_err++;
            break;
        case 12:
            reg->ma_sop_err++;
            break;
        case 13:
            reg->ma_eop_err++;
            break;
        default:
            break;
        }
        delphi::objects::PrprprdintintfMetrics::Publish(key, reg);
        break;
    }
    case 137:
    {
        delphi::objects::ppppintppmetrics_t *reg = &ppppintppmetrics;
        switch (field_id) {
        case 2:
            reg->ppsd_sbe++;
            break;
        case 3:
            reg->ppsd_dbe++;
            break;
        case 4:
            reg->sbus_err++;
            break;
        case 5:
            reg->port7_c_int++;
            break;
        case 6:
            reg->port7_p_int++;
            break;
        case 7:
            reg->port6_c_int++;
            break;
        case 8:
            reg->port6_p_int++;
            break;
        case 9:
            reg->port5_c_int++;
            break;
        case 10:
            reg->port5_p_int++;
            break;
        case 11:
            reg->port4_c_int++;
            break;
        case 12:
            reg->port4_p_int++;
            break;
        case 13:
            reg->port3_c_int++;
            break;
        case 14:
            reg->port3_p_int++;
            break;
        case 15:
            reg->port2_c_int++;
            break;
        case 16:
            reg->port2_p_int++;
            break;
        case 17:
            reg->port1_c_int++;
            break;
        case 18:
            reg->port1_p_int++;
            break;
        case 19:
            reg->port0_c_int++;
            break;
        case 20:
            reg->port0_p_int++;
            break;
        case 21:
            reg->perst7n_dn2up++;
            break;
        case 22:
            reg->perst6n_dn2up++;
            break;
        case 23:
            reg->perst5n_dn2up++;
            break;
        case 24:
            reg->perst4n_dn2up++;
            break;
        case 25:
            reg->perst3n_dn2up++;
            break;
        case 26:
            reg->perst2n_dn2up++;
            break;
        case 27:
            reg->perst1n_dn2up++;
            break;
        case 28:
            reg->perst0n_dn2up++;
            break;
        default:
            break;
        }
        delphi::objects::PpppintppMetrics::Publish(key, reg);
        break;
    }
    case 139:
    {
        delphi::objects::ppppportp0intpeccmetrics_t *reg = &ppppportp0intpeccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbfr_overflow++;
            break;
        case 3:
            reg->replay_bfr_overflow++;
            break;
        case 4:
            reg->rxtlp_err++;
            break;
        case 5:
            reg->txbuf_0_uncorrectable++;
            break;
        case 6:
            reg->txbuf_1_uncorrectable++;
            break;
        case 7:
            reg->txbuf_2_uncorrectable++;
            break;
        case 8:
            reg->txbuf_3_uncorrectable++;
            break;
        case 9:
            reg->txbuf_0_correctable++;
            break;
        case 10:
            reg->txbuf_1_correctable++;
            break;
        case 11:
            reg->txbuf_2_correctable++;
            break;
        case 12:
            reg->txbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportp0intpeccMetrics::Publish(key, reg);
        break;
    }
    case 141:
    {
        delphi::objects::ppppportp1intpeccmetrics_t *reg = &ppppportp1intpeccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbfr_overflow++;
            break;
        case 3:
            reg->replay_bfr_overflow++;
            break;
        case 4:
            reg->rxtlp_err++;
            break;
        case 5:
            reg->txbuf_0_uncorrectable++;
            break;
        case 6:
            reg->txbuf_1_uncorrectable++;
            break;
        case 7:
            reg->txbuf_2_uncorrectable++;
            break;
        case 8:
            reg->txbuf_3_uncorrectable++;
            break;
        case 9:
            reg->txbuf_0_correctable++;
            break;
        case 10:
            reg->txbuf_1_correctable++;
            break;
        case 11:
            reg->txbuf_2_correctable++;
            break;
        case 12:
            reg->txbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportp1intpeccMetrics::Publish(key, reg);
        break;
    }
    case 143:
    {
        delphi::objects::ppppportp2intpeccmetrics_t *reg = &ppppportp2intpeccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbfr_overflow++;
            break;
        case 3:
            reg->replay_bfr_overflow++;
            break;
        case 4:
            reg->rxtlp_err++;
            break;
        case 5:
            reg->txbuf_0_uncorrectable++;
            break;
        case 6:
            reg->txbuf_1_uncorrectable++;
            break;
        case 7:
            reg->txbuf_2_uncorrectable++;
            break;
        case 8:
            reg->txbuf_3_uncorrectable++;
            break;
        case 9:
            reg->txbuf_0_correctable++;
            break;
        case 10:
            reg->txbuf_1_correctable++;
            break;
        case 11:
            reg->txbuf_2_correctable++;
            break;
        case 12:
            reg->txbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportp2intpeccMetrics::Publish(key, reg);
        break;
    }
    case 145:
    {
        delphi::objects::ppppportp3intpeccmetrics_t *reg = &ppppportp3intpeccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbfr_overflow++;
            break;
        case 3:
            reg->replay_bfr_overflow++;
            break;
        case 4:
            reg->rxtlp_err++;
            break;
        case 5:
            reg->txbuf_0_uncorrectable++;
            break;
        case 6:
            reg->txbuf_1_uncorrectable++;
            break;
        case 7:
            reg->txbuf_2_uncorrectable++;
            break;
        case 8:
            reg->txbuf_3_uncorrectable++;
            break;
        case 9:
            reg->txbuf_0_correctable++;
            break;
        case 10:
            reg->txbuf_1_correctable++;
            break;
        case 11:
            reg->txbuf_2_correctable++;
            break;
        case 12:
            reg->txbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportp3intpeccMetrics::Publish(key, reg);
        break;
    }
    case 147:
    {
        delphi::objects::ppppportp4intpeccmetrics_t *reg = &ppppportp4intpeccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbfr_overflow++;
            break;
        case 3:
            reg->replay_bfr_overflow++;
            break;
        case 4:
            reg->rxtlp_err++;
            break;
        case 5:
            reg->txbuf_0_uncorrectable++;
            break;
        case 6:
            reg->txbuf_1_uncorrectable++;
            break;
        case 7:
            reg->txbuf_2_uncorrectable++;
            break;
        case 8:
            reg->txbuf_3_uncorrectable++;
            break;
        case 9:
            reg->txbuf_0_correctable++;
            break;
        case 10:
            reg->txbuf_1_correctable++;
            break;
        case 11:
            reg->txbuf_2_correctable++;
            break;
        case 12:
            reg->txbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportp4intpeccMetrics::Publish(key, reg);
        break;
    }
    case 149:
    {
        delphi::objects::ppppportp5intpeccmetrics_t *reg = &ppppportp5intpeccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbfr_overflow++;
            break;
        case 3:
            reg->replay_bfr_overflow++;
            break;
        case 4:
            reg->rxtlp_err++;
            break;
        case 5:
            reg->txbuf_0_uncorrectable++;
            break;
        case 6:
            reg->txbuf_1_uncorrectable++;
            break;
        case 7:
            reg->txbuf_2_uncorrectable++;
            break;
        case 8:
            reg->txbuf_3_uncorrectable++;
            break;
        case 9:
            reg->txbuf_0_correctable++;
            break;
        case 10:
            reg->txbuf_1_correctable++;
            break;
        case 11:
            reg->txbuf_2_correctable++;
            break;
        case 12:
            reg->txbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportp5intpeccMetrics::Publish(key, reg);
        break;
    }
    case 151:
    {
        delphi::objects::ppppportp6intpeccmetrics_t *reg = &ppppportp6intpeccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbfr_overflow++;
            break;
        case 3:
            reg->replay_bfr_overflow++;
            break;
        case 4:
            reg->rxtlp_err++;
            break;
        case 5:
            reg->txbuf_0_uncorrectable++;
            break;
        case 6:
            reg->txbuf_1_uncorrectable++;
            break;
        case 7:
            reg->txbuf_2_uncorrectable++;
            break;
        case 8:
            reg->txbuf_3_uncorrectable++;
            break;
        case 9:
            reg->txbuf_0_correctable++;
            break;
        case 10:
            reg->txbuf_1_correctable++;
            break;
        case 11:
            reg->txbuf_2_correctable++;
            break;
        case 12:
            reg->txbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportp6intpeccMetrics::Publish(key, reg);
        break;
    }
    case 153:
    {
        delphi::objects::ppppportp7intpeccmetrics_t *reg = &ppppportp7intpeccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbfr_overflow++;
            break;
        case 3:
            reg->replay_bfr_overflow++;
            break;
        case 4:
            reg->rxtlp_err++;
            break;
        case 5:
            reg->txbuf_0_uncorrectable++;
            break;
        case 6:
            reg->txbuf_1_uncorrectable++;
            break;
        case 7:
            reg->txbuf_2_uncorrectable++;
            break;
        case 8:
            reg->txbuf_3_uncorrectable++;
            break;
        case 9:
            reg->txbuf_0_correctable++;
            break;
        case 10:
            reg->txbuf_1_correctable++;
            break;
        case 11:
            reg->txbuf_2_correctable++;
            break;
        case 12:
            reg->txbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportp7intpeccMetrics::Publish(key, reg);
        break;
    }
    case 155:
    {
        delphi::objects::ppppportc0intcmacmetrics_t *reg = &ppppportc0intcmacmetrics;
        switch (field_id) {
        case 2:
            reg->link_dn2up++;
            break;
        case 3:
            reg->link_up2dn++;
            break;
        case 4:
            reg->sec_bus_rst++;
            break;
        case 5:
            reg->rst_up2dn++;
            break;
        case 6:
            reg->rst_dn2up++;
            break;
        case 7:
            reg->portgate_open2close++;
            break;
        case 8:
            reg->ltssm_st_changed++;
            break;
        case 9:
            reg->sec_busnum_changed++;
            break;
        case 10:
            reg->rc_pme++;
            break;
        case 11:
            reg->rc_aerr++;
            break;
        case 12:
            reg->rc_serr++;
            break;
        case 13:
            reg->rc_hpe++;
            break;
        case 14:
            reg->rc_eq_req++;
            break;
        case 15:
            reg->rc_dpc++;
            break;
        case 16:
            reg->pm_turnoff++;
            break;
        case 17:
            reg->txbfr_overflow++;
            break;
        case 18:
            reg->rxtlp_err++;
            break;
        case 19:
            reg->tl_flr_req++;
            break;
        case 20:
            reg->rc_legacy_intpin_changed++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc0intcmacMetrics::Publish(key, reg);
        break;
    }
    case 156:
    {
        delphi::objects::ppppportc0intceccmetrics_t *reg = &ppppportc0intceccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbuf_0_uncorrectable++;
            break;
        case 3:
            reg->rxbuf_1_uncorrectable++;
            break;
        case 4:
            reg->rxbuf_2_uncorrectable++;
            break;
        case 5:
            reg->rxbuf_3_uncorrectable++;
            break;
        case 6:
            reg->rxbuf_0_correctable++;
            break;
        case 7:
            reg->rxbuf_1_correctable++;
            break;
        case 8:
            reg->rxbuf_2_correctable++;
            break;
        case 9:
            reg->rxbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc0intceccMetrics::Publish(key, reg);
        break;
    }
    case 158:
    {
        delphi::objects::ppppportc1intcmacmetrics_t *reg = &ppppportc1intcmacmetrics;
        switch (field_id) {
        case 2:
            reg->link_dn2up++;
            break;
        case 3:
            reg->link_up2dn++;
            break;
        case 4:
            reg->sec_bus_rst++;
            break;
        case 5:
            reg->rst_up2dn++;
            break;
        case 6:
            reg->rst_dn2up++;
            break;
        case 7:
            reg->portgate_open2close++;
            break;
        case 8:
            reg->ltssm_st_changed++;
            break;
        case 9:
            reg->sec_busnum_changed++;
            break;
        case 10:
            reg->rc_pme++;
            break;
        case 11:
            reg->rc_aerr++;
            break;
        case 12:
            reg->rc_serr++;
            break;
        case 13:
            reg->rc_hpe++;
            break;
        case 14:
            reg->rc_eq_req++;
            break;
        case 15:
            reg->rc_dpc++;
            break;
        case 16:
            reg->pm_turnoff++;
            break;
        case 17:
            reg->txbfr_overflow++;
            break;
        case 18:
            reg->rxtlp_err++;
            break;
        case 19:
            reg->tl_flr_req++;
            break;
        case 20:
            reg->rc_legacy_intpin_changed++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc1intcmacMetrics::Publish(key, reg);
        break;
    }
    case 159:
    {
        delphi::objects::ppppportc1intceccmetrics_t *reg = &ppppportc1intceccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbuf_0_uncorrectable++;
            break;
        case 3:
            reg->rxbuf_1_uncorrectable++;
            break;
        case 4:
            reg->rxbuf_2_uncorrectable++;
            break;
        case 5:
            reg->rxbuf_3_uncorrectable++;
            break;
        case 6:
            reg->rxbuf_0_correctable++;
            break;
        case 7:
            reg->rxbuf_1_correctable++;
            break;
        case 8:
            reg->rxbuf_2_correctable++;
            break;
        case 9:
            reg->rxbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc1intceccMetrics::Publish(key, reg);
        break;
    }
    case 161:
    {
        delphi::objects::ppppportc2intcmacmetrics_t *reg = &ppppportc2intcmacmetrics;
        switch (field_id) {
        case 2:
            reg->link_dn2up++;
            break;
        case 3:
            reg->link_up2dn++;
            break;
        case 4:
            reg->sec_bus_rst++;
            break;
        case 5:
            reg->rst_up2dn++;
            break;
        case 6:
            reg->rst_dn2up++;
            break;
        case 7:
            reg->portgate_open2close++;
            break;
        case 8:
            reg->ltssm_st_changed++;
            break;
        case 9:
            reg->sec_busnum_changed++;
            break;
        case 10:
            reg->rc_pme++;
            break;
        case 11:
            reg->rc_aerr++;
            break;
        case 12:
            reg->rc_serr++;
            break;
        case 13:
            reg->rc_hpe++;
            break;
        case 14:
            reg->rc_eq_req++;
            break;
        case 15:
            reg->rc_dpc++;
            break;
        case 16:
            reg->pm_turnoff++;
            break;
        case 17:
            reg->txbfr_overflow++;
            break;
        case 18:
            reg->rxtlp_err++;
            break;
        case 19:
            reg->tl_flr_req++;
            break;
        case 20:
            reg->rc_legacy_intpin_changed++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc2intcmacMetrics::Publish(key, reg);
        break;
    }
    case 162:
    {
        delphi::objects::ppppportc2intceccmetrics_t *reg = &ppppportc2intceccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbuf_0_uncorrectable++;
            break;
        case 3:
            reg->rxbuf_1_uncorrectable++;
            break;
        case 4:
            reg->rxbuf_2_uncorrectable++;
            break;
        case 5:
            reg->rxbuf_3_uncorrectable++;
            break;
        case 6:
            reg->rxbuf_0_correctable++;
            break;
        case 7:
            reg->rxbuf_1_correctable++;
            break;
        case 8:
            reg->rxbuf_2_correctable++;
            break;
        case 9:
            reg->rxbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc2intceccMetrics::Publish(key, reg);
        break;
    }
    case 164:
    {
        delphi::objects::ppppportc3intcmacmetrics_t *reg = &ppppportc3intcmacmetrics;
        switch (field_id) {
        case 2:
            reg->link_dn2up++;
            break;
        case 3:
            reg->link_up2dn++;
            break;
        case 4:
            reg->sec_bus_rst++;
            break;
        case 5:
            reg->rst_up2dn++;
            break;
        case 6:
            reg->rst_dn2up++;
            break;
        case 7:
            reg->portgate_open2close++;
            break;
        case 8:
            reg->ltssm_st_changed++;
            break;
        case 9:
            reg->sec_busnum_changed++;
            break;
        case 10:
            reg->rc_pme++;
            break;
        case 11:
            reg->rc_aerr++;
            break;
        case 12:
            reg->rc_serr++;
            break;
        case 13:
            reg->rc_hpe++;
            break;
        case 14:
            reg->rc_eq_req++;
            break;
        case 15:
            reg->rc_dpc++;
            break;
        case 16:
            reg->pm_turnoff++;
            break;
        case 17:
            reg->txbfr_overflow++;
            break;
        case 18:
            reg->rxtlp_err++;
            break;
        case 19:
            reg->tl_flr_req++;
            break;
        case 20:
            reg->rc_legacy_intpin_changed++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc3intcmacMetrics::Publish(key, reg);
        break;
    }
    case 165:
    {
        delphi::objects::ppppportc3intceccmetrics_t *reg = &ppppportc3intceccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbuf_0_uncorrectable++;
            break;
        case 3:
            reg->rxbuf_1_uncorrectable++;
            break;
        case 4:
            reg->rxbuf_2_uncorrectable++;
            break;
        case 5:
            reg->rxbuf_3_uncorrectable++;
            break;
        case 6:
            reg->rxbuf_0_correctable++;
            break;
        case 7:
            reg->rxbuf_1_correctable++;
            break;
        case 8:
            reg->rxbuf_2_correctable++;
            break;
        case 9:
            reg->rxbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc3intceccMetrics::Publish(key, reg);
        break;
    }
    case 167:
    {
        delphi::objects::ppppportc4intcmacmetrics_t *reg = &ppppportc4intcmacmetrics;
        switch (field_id) {
        case 2:
            reg->link_dn2up++;
            break;
        case 3:
            reg->link_up2dn++;
            break;
        case 4:
            reg->sec_bus_rst++;
            break;
        case 5:
            reg->rst_up2dn++;
            break;
        case 6:
            reg->rst_dn2up++;
            break;
        case 7:
            reg->portgate_open2close++;
            break;
        case 8:
            reg->ltssm_st_changed++;
            break;
        case 9:
            reg->sec_busnum_changed++;
            break;
        case 10:
            reg->rc_pme++;
            break;
        case 11:
            reg->rc_aerr++;
            break;
        case 12:
            reg->rc_serr++;
            break;
        case 13:
            reg->rc_hpe++;
            break;
        case 14:
            reg->rc_eq_req++;
            break;
        case 15:
            reg->rc_dpc++;
            break;
        case 16:
            reg->pm_turnoff++;
            break;
        case 17:
            reg->txbfr_overflow++;
            break;
        case 18:
            reg->rxtlp_err++;
            break;
        case 19:
            reg->tl_flr_req++;
            break;
        case 20:
            reg->rc_legacy_intpin_changed++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc4intcmacMetrics::Publish(key, reg);
        break;
    }
    case 168:
    {
        delphi::objects::ppppportc4intceccmetrics_t *reg = &ppppportc4intceccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbuf_0_uncorrectable++;
            break;
        case 3:
            reg->rxbuf_1_uncorrectable++;
            break;
        case 4:
            reg->rxbuf_2_uncorrectable++;
            break;
        case 5:
            reg->rxbuf_3_uncorrectable++;
            break;
        case 6:
            reg->rxbuf_0_correctable++;
            break;
        case 7:
            reg->rxbuf_1_correctable++;
            break;
        case 8:
            reg->rxbuf_2_correctable++;
            break;
        case 9:
            reg->rxbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc4intceccMetrics::Publish(key, reg);
        break;
    }
    case 170:
    {
        delphi::objects::ppppportc5intcmacmetrics_t *reg = &ppppportc5intcmacmetrics;
        switch (field_id) {
        case 2:
            reg->link_dn2up++;
            break;
        case 3:
            reg->link_up2dn++;
            break;
        case 4:
            reg->sec_bus_rst++;
            break;
        case 5:
            reg->rst_up2dn++;
            break;
        case 6:
            reg->rst_dn2up++;
            break;
        case 7:
            reg->portgate_open2close++;
            break;
        case 8:
            reg->ltssm_st_changed++;
            break;
        case 9:
            reg->sec_busnum_changed++;
            break;
        case 10:
            reg->rc_pme++;
            break;
        case 11:
            reg->rc_aerr++;
            break;
        case 12:
            reg->rc_serr++;
            break;
        case 13:
            reg->rc_hpe++;
            break;
        case 14:
            reg->rc_eq_req++;
            break;
        case 15:
            reg->rc_dpc++;
            break;
        case 16:
            reg->pm_turnoff++;
            break;
        case 17:
            reg->txbfr_overflow++;
            break;
        case 18:
            reg->rxtlp_err++;
            break;
        case 19:
            reg->tl_flr_req++;
            break;
        case 20:
            reg->rc_legacy_intpin_changed++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc5intcmacMetrics::Publish(key, reg);
        break;
    }
    case 171:
    {
        delphi::objects::ppppportc5intceccmetrics_t *reg = &ppppportc5intceccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbuf_0_uncorrectable++;
            break;
        case 3:
            reg->rxbuf_1_uncorrectable++;
            break;
        case 4:
            reg->rxbuf_2_uncorrectable++;
            break;
        case 5:
            reg->rxbuf_3_uncorrectable++;
            break;
        case 6:
            reg->rxbuf_0_correctable++;
            break;
        case 7:
            reg->rxbuf_1_correctable++;
            break;
        case 8:
            reg->rxbuf_2_correctable++;
            break;
        case 9:
            reg->rxbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc5intceccMetrics::Publish(key, reg);
        break;
    }
    case 173:
    {
        delphi::objects::ppppportc6intcmacmetrics_t *reg = &ppppportc6intcmacmetrics;
        switch (field_id) {
        case 2:
            reg->link_dn2up++;
            break;
        case 3:
            reg->link_up2dn++;
            break;
        case 4:
            reg->sec_bus_rst++;
            break;
        case 5:
            reg->rst_up2dn++;
            break;
        case 6:
            reg->rst_dn2up++;
            break;
        case 7:
            reg->portgate_open2close++;
            break;
        case 8:
            reg->ltssm_st_changed++;
            break;
        case 9:
            reg->sec_busnum_changed++;
            break;
        case 10:
            reg->rc_pme++;
            break;
        case 11:
            reg->rc_aerr++;
            break;
        case 12:
            reg->rc_serr++;
            break;
        case 13:
            reg->rc_hpe++;
            break;
        case 14:
            reg->rc_eq_req++;
            break;
        case 15:
            reg->rc_dpc++;
            break;
        case 16:
            reg->pm_turnoff++;
            break;
        case 17:
            reg->txbfr_overflow++;
            break;
        case 18:
            reg->rxtlp_err++;
            break;
        case 19:
            reg->tl_flr_req++;
            break;
        case 20:
            reg->rc_legacy_intpin_changed++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc6intcmacMetrics::Publish(key, reg);
        break;
    }
    case 174:
    {
        delphi::objects::ppppportc6intceccmetrics_t *reg = &ppppportc6intceccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbuf_0_uncorrectable++;
            break;
        case 3:
            reg->rxbuf_1_uncorrectable++;
            break;
        case 4:
            reg->rxbuf_2_uncorrectable++;
            break;
        case 5:
            reg->rxbuf_3_uncorrectable++;
            break;
        case 6:
            reg->rxbuf_0_correctable++;
            break;
        case 7:
            reg->rxbuf_1_correctable++;
            break;
        case 8:
            reg->rxbuf_2_correctable++;
            break;
        case 9:
            reg->rxbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc6intceccMetrics::Publish(key, reg);
        break;
    }
    case 176:
    {
        delphi::objects::ppppportc7intcmacmetrics_t *reg = &ppppportc7intcmacmetrics;
        switch (field_id) {
        case 2:
            reg->link_dn2up++;
            break;
        case 3:
            reg->link_up2dn++;
            break;
        case 4:
            reg->sec_bus_rst++;
            break;
        case 5:
            reg->rst_up2dn++;
            break;
        case 6:
            reg->rst_dn2up++;
            break;
        case 7:
            reg->portgate_open2close++;
            break;
        case 8:
            reg->ltssm_st_changed++;
            break;
        case 9:
            reg->sec_busnum_changed++;
            break;
        case 10:
            reg->rc_pme++;
            break;
        case 11:
            reg->rc_aerr++;
            break;
        case 12:
            reg->rc_serr++;
            break;
        case 13:
            reg->rc_hpe++;
            break;
        case 14:
            reg->rc_eq_req++;
            break;
        case 15:
            reg->rc_dpc++;
            break;
        case 16:
            reg->pm_turnoff++;
            break;
        case 17:
            reg->txbfr_overflow++;
            break;
        case 18:
            reg->rxtlp_err++;
            break;
        case 19:
            reg->tl_flr_req++;
            break;
        case 20:
            reg->rc_legacy_intpin_changed++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc7intcmacMetrics::Publish(key, reg);
        break;
    }
    case 177:
    {
        delphi::objects::ppppportc7intceccmetrics_t *reg = &ppppportc7intceccmetrics;
        switch (field_id) {
        case 2:
            reg->rxbuf_0_uncorrectable++;
            break;
        case 3:
            reg->rxbuf_1_uncorrectable++;
            break;
        case 4:
            reg->rxbuf_2_uncorrectable++;
            break;
        case 5:
            reg->rxbuf_3_uncorrectable++;
            break;
        case 6:
            reg->rxbuf_0_correctable++;
            break;
        case 7:
            reg->rxbuf_1_correctable++;
            break;
        case 8:
            reg->rxbuf_2_correctable++;
            break;
        case 9:
            reg->rxbuf_3_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Ppppportc7intceccMetrics::Publish(key, reg);
        break;
    }
    case 179:
    {
        delphi::objects::ptptintreg1metrics_t *reg = &ptptintreg1metrics;
        switch (field_id) {
        case 2:
            reg->slave_ptd++;
            break;
        case 3:
            reg->slave_psp++;
            break;
        default:
            break;
        }
        delphi::objects::Ptptintreg1Metrics::Publish(key, reg);
        break;
    }
    case 181:
    {
        delphi::objects::ptptpspintinfometrics_t *reg = &ptptpspintinfometrics;
        switch (field_id) {
        case 2:
            reg->pr_pkt_ff_almost_full++;
            break;
        case 3:
            reg->ptd_npv_phv_full++;
            break;
        case 4:
            reg->phv_srdy_collapsed++;
            break;
        case 5:
            reg->pr_resub_pkt_before_phv++;
            break;
        case 6:
            reg->pb_pbus_fsm0_no_data++;
            break;
        case 7:
            reg->pb_pbus_fsm1_no_data++;
            break;
        case 8:
            reg->pb_pbus_fsm2_no_data++;
            break;
        case 9:
            reg->pb_pbus_fsm3_no_data++;
            break;
        case 10:
            reg->pb_pbus_fsm4_no_data++;
            break;
        default:
            break;
        }
        delphi::objects::PtptpspintinfoMetrics::Publish(key, reg);
        break;
    }
    case 182:
    {
        delphi::objects::ptptpspinterrmetrics_t *reg = &ptptpspinterrmetrics;
        switch (field_id) {
        case 2:
            reg->pb_pbus_err++;
            break;
        case 3:
            reg->pr_pbus_err++;
            break;
        case 4:
            reg->pr_resub_pbus_err++;
            break;
        case 5:
            reg->psp_csr_read_access_err++;
            break;
        case 6:
            reg->psp_csr_write_access_err++;
            break;
        case 7:
            reg->psp_phv_larger_than_twelve_flits_err++;
            break;
        case 8:
            reg->psp_phv_sop_offset_err++;
            break;
        case 9:
            reg->psp_phv_eop_offset_err++;
            break;
        case 10:
            reg->max_recir_count_err++;
            break;
        case 11:
            reg->pb_pbus_dummy_err++;
            break;
        case 12:
            reg->pb_pbus_nopkt_err++;
            break;
        case 13:
            reg->pb_pbus_min_err++;
            break;
        case 14:
            reg->lb_phv_almost_full_timeout_err++;
            break;
        case 15:
            reg->lb_pkt_almost_full_timeout_err++;
            break;
        default:
            break;
        }
        delphi::objects::PtptpspinterrMetrics::Publish(key, reg);
        break;
    }
    case 183:
    {
        delphi::objects::ptptpspintfatalmetrics_t *reg = &ptptpspintfatalmetrics;
        switch (field_id) {
        case 2:
            reg->pb_pbus_sop_err++;
            break;
        case 3:
            reg->pb_pbus_eop_err++;
            break;
        case 4:
            reg->ma_sop_err++;
            break;
        case 5:
            reg->ma_eop_err++;
            break;
        case 6:
            reg->pr_pbus_sop_err++;
            break;
        case 7:
            reg->pr_pbus_eop_err++;
            break;
        case 8:
            reg->pr_resub_pbus_sop_err++;
            break;
        case 9:
            reg->pr_resub_pbus_eop_err++;
            break;
        case 10:
            reg->pr_resub_sop_err++;
            break;
        case 11:
            reg->pr_resub_eop_err++;
            break;
        case 12:
            reg->pb_pbus_fsm0_no_data_err++;
            break;
        case 13:
            reg->pb_pbus_fsm1_no_data_err++;
            break;
        case 14:
            reg->pb_pbus_fsm2_no_data_err++;
            break;
        case 15:
            reg->pb_pbus_fsm3_no_data_err++;
            break;
        case 16:
            reg->pb_pbus_fsm4_no_data_err++;
            break;
        case 17:
            reg->pb_pbus_fsm5_pkt_too_small_err++;
            break;
        case 18:
            reg->lif_ind_table_rsp_err++;
            break;
        case 19:
            reg->flit_cnt_oflow_err++;
            break;
        case 20:
            reg->lb_phv_sop_err++;
            break;
        case 21:
            reg->dc_phv_sop_err++;
            break;
        case 22:
            reg->lb_pkt_sop_err++;
            break;
        case 23:
            reg->dc_pkt_sop_err++;
            break;
        case 24:
            reg->sw_phv_jabber_err++;
            break;
        default:
            break;
        }
        delphi::objects::PtptpspintfatalMetrics::Publish(key, reg);
        break;
    }
    case 184:
    {
        delphi::objects::ptptpspintlifqstatemapmetrics_t *reg = &ptptpspintlifqstatemapmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_uncorrectable++;
            break;
        case 3:
            reg->ecc_correctable++;
            break;
        case 4:
            reg->qid_invalid++;
            break;
        default:
            break;
        }
        delphi::objects::PtptpspintlifqstatemapMetrics::Publish(key, reg);
        break;
    }
    case 185:
    {
        delphi::objects::ptptpspintswphvmemmetrics_t *reg = &ptptpspintswphvmemmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_uncorrectable++;
            break;
        case 3:
            reg->ecc_correctable++;
            break;
        case 4:
            reg->phv_invalid_sram++;
            break;
        case 5:
            reg->phv_invalid_data++;
            break;
        case 6:
            reg->phv_done0++;
            break;
        case 7:
            reg->phv_done1++;
            break;
        case 8:
            reg->phv_done2++;
            break;
        case 9:
            reg->phv_done3++;
            break;
        case 10:
            reg->phv_done4++;
            break;
        case 11:
            reg->phv_done5++;
            break;
        case 12:
            reg->phv_done6++;
            break;
        case 13:
            reg->phv_done7++;
            break;
        default:
            break;
        }
        delphi::objects::PtptpspintswphvmemMetrics::Publish(key, reg);
        break;
    }
    case 187:
    {
        delphi::objects::ptptptdinteccmetrics_t *reg = &ptptptdinteccmetrics;
        switch (field_id) {
        case 2:
            reg->rdata_mem_uncorrectable++;
            break;
        case 3:
            reg->rdata_mem_correctable++;
            break;
        case 4:
            reg->lat_mem_uncorrectable++;
            break;
        case 5:
            reg->lat_mem_correctable++;
            break;
        case 6:
            reg->wdata_mem_uncorrectable++;
            break;
        case 7:
            reg->wdata_mem_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PtptptdinteccMetrics::Publish(key, reg);
        break;
    }
    case 188:
    {
        delphi::objects::ptptptdintfifometrics_t *reg = &ptptptdintfifometrics;
        switch (field_id) {
        case 2:
            reg->lat_ff_ovflow++;
            break;
        case 3:
            reg->wdata_ff_ovflow++;
            break;
        case 4:
            reg->rcv_stg_ff_ovflow++;
            break;
        case 5:
            reg->cmdflit_ff_ovflow++;
            break;
        case 6:
            reg->cmd_ff_ovflow++;
            break;
        case 7:
            reg->pkt_ff_ovflow++;
            break;
        case 8:
            reg->wr_mem_ff_ovflow++;
            break;
        case 9:
            reg->dfence_ff_ovflow++;
            break;
        case 10:
            reg->ffence_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::PtptptdintfifoMetrics::Publish(key, reg);
        break;
    }
    case 189:
    {
        delphi::objects::ptptptdintgrp1metrics_t *reg = &ptptptdintgrp1metrics;
        switch (field_id) {
        case 2:
            reg->rcv_phv_dma_ptr++;
            break;
        case 3:
            reg->rcv_phv_addr++;
            break;
        case 4:
            reg->rcv_exceed_16byte++;
            break;
        case 5:
            reg->rcv_phv_not_sop++;
            break;
        case 6:
            reg->rcv_pkt_order_ff_full++;
            break;
        case 7:
            reg->rcv_pend_phv_more_than_2++;
            break;
        case 8:
            reg->rcv_pend_phv_less++;
            break;
        case 9:
            reg->rcv_cmd_nop_eop++;
            break;
        case 10:
            reg->rcv_cmd_out_not_sop++;
            break;
        case 11:
            reg->rcv_pkt2mem_seen++;
            break;
        case 12:
            reg->rcv_skip_seen++;
            break;
        case 13:
            reg->rcv_phv_eop_no_cmd_eop++;
            break;
        case 14:
            reg->rcv_m2m_dst_not_seen++;
            break;
        case 15:
            reg->rcv_m2m_src_not_seen++;
            break;
        case 16:
            reg->rdreq_invalid_cmd_seen++;
            break;
        case 17:
            reg->rdreq_mem2mem_psize_zero++;
            break;
        case 18:
            reg->rdreq_m2m_phv2mem_exceed_16byte++;
            break;
        case 19:
            reg->rdreq_phv2mem_fence_exceed_16byte++;
            break;
        case 20:
            reg->rdreq_mem2pkt_psize_zero++;
            break;
        default:
            break;
        }
        delphi::objects::Ptptptdintgrp1Metrics::Publish(key, reg);
        break;
    }
    case 190:
    {
        delphi::objects::ptptptdintgrp2metrics_t *reg = &ptptptdintgrp2metrics;
        switch (field_id) {
        case 2:
            reg->wr_invalid_cmd++;
            break;
        case 3:
            reg->wr_pend_sz++;
            break;
        case 4:
            reg->wr_axi_rd_resp++;
            break;
        case 5:
            reg->pkt_err_eop_forced++;
            break;
        case 6:
            reg->pkt_no_eop_err_seen++;
            break;
        case 7:
            reg->pkt_cmd_eop_no_data++;
            break;
        case 8:
            reg->rdrsp_axi++;
            break;
        case 9:
            reg->wrrsp_axi++;
            break;
        case 10:
            reg->spurious_rd_resp++;
            break;
        case 11:
            reg->spurious_wr_resp++;
            break;
        case 12:
            reg->wrreq_info_first_missing++;
            break;
        case 13:
            reg->wrreq_num_bytes_zero++;
            break;
        case 14:
            reg->wrreq_num_bytes_more_than_64++;
            break;
        default:
            break;
        }
        delphi::objects::Ptptptdintgrp2Metrics::Publish(key, reg);
        break;
    }
    case 191:
    {
        delphi::objects::ptptptdintintfmetrics_t *reg = &ptptptdintintfmetrics;
        switch (field_id) {
        case 2:
            reg->pb_err++;
            break;
        case 3:
            reg->pb_sop_err++;
            break;
        case 4:
            reg->pb_eop_err++;
            break;
        case 5:
            reg->npv_resub_err++;
            break;
        case 6:
            reg->npv_resub_sop_err++;
            break;
        case 7:
            reg->npv_resub_eop_err++;
            break;
        case 8:
            reg->ma_err++;
            break;
        case 9:
            reg->ma_sop_err++;
            break;
        case 10:
            reg->ma_eop_err++;
            break;
        default:
            break;
        }
        delphi::objects::PtptptdintintfMetrics::Publish(key, reg);
        break;
    }
    case 193:
    {
        delphi::objects::pcrte0interrmetrics_t *reg = &pcrte0interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte0interrMetrics::Publish(key, reg);
        break;
    }
    case 194:
    {
        delphi::objects::pcrte0intinfometrics_t *reg = &pcrte0intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte0intinfoMetrics::Publish(key, reg);
        break;
    }
    case 196:
    {
        delphi::objects::pcrte1interrmetrics_t *reg = &pcrte1interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte1interrMetrics::Publish(key, reg);
        break;
    }
    case 197:
    {
        delphi::objects::pcrte1intinfometrics_t *reg = &pcrte1intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte1intinfoMetrics::Publish(key, reg);
        break;
    }
    case 199:
    {
        delphi::objects::pcrte2interrmetrics_t *reg = &pcrte2interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte2interrMetrics::Publish(key, reg);
        break;
    }
    case 200:
    {
        delphi::objects::pcrte2intinfometrics_t *reg = &pcrte2intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte2intinfoMetrics::Publish(key, reg);
        break;
    }
    case 202:
    {
        delphi::objects::pcrte3interrmetrics_t *reg = &pcrte3interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte3interrMetrics::Publish(key, reg);
        break;
    }
    case 203:
    {
        delphi::objects::pcrte3intinfometrics_t *reg = &pcrte3intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte3intinfoMetrics::Publish(key, reg);
        break;
    }
    case 205:
    {
        delphi::objects::pcrte4interrmetrics_t *reg = &pcrte4interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte4interrMetrics::Publish(key, reg);
        break;
    }
    case 206:
    {
        delphi::objects::pcrte4intinfometrics_t *reg = &pcrte4intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte4intinfoMetrics::Publish(key, reg);
        break;
    }
    case 208:
    {
        delphi::objects::pcrte5interrmetrics_t *reg = &pcrte5interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte5interrMetrics::Publish(key, reg);
        break;
    }
    case 209:
    {
        delphi::objects::pcrte5intinfometrics_t *reg = &pcrte5intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte5intinfoMetrics::Publish(key, reg);
        break;
    }
    case 211:
    {
        delphi::objects::pcrte6interrmetrics_t *reg = &pcrte6interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte6interrMetrics::Publish(key, reg);
        break;
    }
    case 212:
    {
        delphi::objects::pcrte6intinfometrics_t *reg = &pcrte6intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte6intinfoMetrics::Publish(key, reg);
        break;
    }
    case 214:
    {
        delphi::objects::pcrte7interrmetrics_t *reg = &pcrte7interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte7interrMetrics::Publish(key, reg);
        break;
    }
    case 215:
    {
        delphi::objects::pcrte7intinfometrics_t *reg = &pcrte7intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrte7intinfoMetrics::Publish(key, reg);
        break;
    }
    case 217:
    {
        delphi::objects::pcrmpu0interrmetrics_t *reg = &pcrmpu0interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu0interrMetrics::Publish(key, reg);
        break;
    }
    case 218:
    {
        delphi::objects::pcrmpu0intinfometrics_t *reg = &pcrmpu0intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu0intinfoMetrics::Publish(key, reg);
        break;
    }
    case 220:
    {
        delphi::objects::pcrmpu1interrmetrics_t *reg = &pcrmpu1interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu1interrMetrics::Publish(key, reg);
        break;
    }
    case 221:
    {
        delphi::objects::pcrmpu1intinfometrics_t *reg = &pcrmpu1intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu1intinfoMetrics::Publish(key, reg);
        break;
    }
    case 223:
    {
        delphi::objects::pcrmpu2interrmetrics_t *reg = &pcrmpu2interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu2interrMetrics::Publish(key, reg);
        break;
    }
    case 224:
    {
        delphi::objects::pcrmpu2intinfometrics_t *reg = &pcrmpu2intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu2intinfoMetrics::Publish(key, reg);
        break;
    }
    case 226:
    {
        delphi::objects::pcrmpu3interrmetrics_t *reg = &pcrmpu3interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu3interrMetrics::Publish(key, reg);
        break;
    }
    case 227:
    {
        delphi::objects::pcrmpu3intinfometrics_t *reg = &pcrmpu3intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu3intinfoMetrics::Publish(key, reg);
        break;
    }
    case 229:
    {
        delphi::objects::pcrmpu4interrmetrics_t *reg = &pcrmpu4interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu4interrMetrics::Publish(key, reg);
        break;
    }
    case 230:
    {
        delphi::objects::pcrmpu4intinfometrics_t *reg = &pcrmpu4intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu4intinfoMetrics::Publish(key, reg);
        break;
    }
    case 232:
    {
        delphi::objects::pcrmpu5interrmetrics_t *reg = &pcrmpu5interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu5interrMetrics::Publish(key, reg);
        break;
    }
    case 233:
    {
        delphi::objects::pcrmpu5intinfometrics_t *reg = &pcrmpu5intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu5intinfoMetrics::Publish(key, reg);
        break;
    }
    case 235:
    {
        delphi::objects::pcrmpu6interrmetrics_t *reg = &pcrmpu6interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu6interrMetrics::Publish(key, reg);
        break;
    }
    case 236:
    {
        delphi::objects::pcrmpu6intinfometrics_t *reg = &pcrmpu6intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu6intinfoMetrics::Publish(key, reg);
        break;
    }
    case 238:
    {
        delphi::objects::pcrmpu7interrmetrics_t *reg = &pcrmpu7interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu7interrMetrics::Publish(key, reg);
        break;
    }
    case 239:
    {
        delphi::objects::pcrmpu7intinfometrics_t *reg = &pcrmpu7intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pcrmpu7intinfoMetrics::Publish(key, reg);
        break;
    }
    case 241:
    {
        delphi::objects::txstxsintschmetrics_t *reg = &txstxsintschmetrics;
        switch (field_id) {
        case 2:
            reg->sch_wid_empty++;
            break;
        case 3:
            reg->sch_rid_empty++;
            break;
        case 4:
            reg->sch_wr_txfifo_ovf++;
            break;
        case 5:
            reg->sch_rd_txfifo_ovf++;
            break;
        case 6:
            reg->sch_state_fifo_ovf++;
            break;
        case 7:
            reg->sch_drb_cnt_qid_fifo++;
            break;
        case 8:
            reg->sch_hbm_byp_ovf++;
            break;
        case 9:
            reg->sch_hbm_byp_wtag_wrap++;
            break;
        case 10:
            reg->sch_rlid_ovfl++;
            break;
        case 11:
            reg->sch_rlid_unfl++;
            break;
        case 12:
            reg->sch_null_lif++;
            break;
        case 13:
            reg->sch_lif_sg_mismatch++;
            break;
        case 14:
            reg->sch_aclr_hbm_ln_rollovr++;
            break;
        case 15:
            reg->sch_txdma_msg_efull++;
            break;
        case 16:
            reg->sch_hbm_re_efull++;
            break;
        case 17:
            reg->sch_hbm_we_efull++;
            break;
        case 18:
            reg->sch_hbm_byp_pending_efull++;
            break;
        case 19:
            reg->sch_hbm_rd_pending_efull++;
            break;
        case 20:
            reg->sch_hbm_wr_pending_efull++;
            break;
        case 21:
            reg->sch_bresp_err++;
            break;
        case 22:
            reg->sch_bid_err++;
            break;
        case 23:
            reg->sch_rresp_err++;
            break;
        case 24:
            reg->sch_rid_err++;
            break;
        case 25:
            reg->sch_drb_cnt_ovfl++;
            break;
        case 26:
            reg->sch_drb_cnt_unfl++;
            break;
        case 27:
            reg->sch_txdma_msg_ovfl++;
            break;
        default:
            break;
        }
        delphi::objects::TxstxsintschMetrics::Publish(key, reg);
        break;
    }
    case 242:
    {
        delphi::objects::txstxsinttmrmetrics_t *reg = &txstxsinttmrmetrics;
        switch (field_id) {
        case 2:
            reg->tmr_wid_empty++;
            break;
        case 3:
            reg->tmr_rid_empty++;
            break;
        case 4:
            reg->tmr_wr_txfifo_ovf++;
            break;
        case 5:
            reg->tmr_rd_txfifo_ovf++;
            break;
        case 6:
            reg->tmr_state_fifo_ovf++;
            break;
        case 7:
            reg->tmr_hbm_byp_ovf++;
            break;
        case 8:
            reg->tmr_hbm_byp_wtag_wrap++;
            break;
        case 9:
            reg->ftmr_ctime_wrap++;
            break;
        case 10:
            reg->stmr_ctime_wrap++;
            break;
        case 11:
            reg->stmr_push_out_of_wheel++;
            break;
        case 12:
            reg->ftmr_push_out_of_wheel++;
            break;
        case 13:
            reg->ftmr_key_not_push++;
            break;
        case 14:
            reg->ftmr_key_not_found++;
            break;
        case 15:
            reg->stmr_key_not_push++;
            break;
        case 16:
            reg->stmr_key_not_found++;
            break;
        case 17:
            reg->stmr_stall++;
            break;
        case 18:
            reg->ftmr_stall++;
            break;
        case 19:
            reg->ftmr_fifo_ovf++;
            break;
        case 20:
            reg->stmr_fifo_ovf++;
            break;
        case 21:
            reg->ftmr_fifo_efull++;
            break;
        case 22:
            reg->stmr_fifo_efull++;
            break;
        case 23:
            reg->tmr_rejct_drb_ovf++;
            break;
        case 24:
            reg->tmr_rejct_drb_efull++;
            break;
        case 25:
            reg->tmr_hbm_re_efull++;
            break;
        case 26:
            reg->tmr_hbm_we_efull++;
            break;
        case 27:
            reg->tmr_hbm_byp_pending_efull++;
            break;
        case 28:
            reg->tmr_hbm_rd_pending_efull++;
            break;
        case 29:
            reg->tmr_hbm_wr_pending_efull++;
            break;
        case 30:
            reg->tmr_bresp_err++;
            break;
        case 31:
            reg->tmr_bid_err++;
            break;
        case 32:
            reg->tmr_rresp_err++;
            break;
        case 33:
            reg->tmr_rid_err++;
            break;
        default:
            break;
        }
        delphi::objects::TxstxsinttmrMetrics::Publish(key, reg);
        break;
    }
    case 243:
    {
        delphi::objects::txstxsintsramseccmetrics_t *reg = &txstxsintsramseccmetrics;
        switch (field_id) {
        case 2:
            reg->tmr_cnt_uncorrectable++;
            break;
        case 3:
            reg->tmr_cnt_correctable++;
            break;
        case 4:
            reg->sch_lif_map_uncorrectable++;
            break;
        case 5:
            reg->sch_lif_map_correctable++;
            break;
        case 6:
            reg->sch_rlid_map_uncorrectable++;
            break;
        case 7:
            reg->sch_rlid_map_correctable++;
            break;
        case 8:
            reg->sch_grp_uncorrectable++;
            break;
        case 9:
            reg->sch_grp_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::TxstxsintsramseccMetrics::Publish(key, reg);
        break;
    }
    case 245:
    {
        delphi::objects::pctte0interrmetrics_t *reg = &pctte0interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte0interrMetrics::Publish(key, reg);
        break;
    }
    case 246:
    {
        delphi::objects::pctte0intinfometrics_t *reg = &pctte0intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte0intinfoMetrics::Publish(key, reg);
        break;
    }
    case 248:
    {
        delphi::objects::pctte1interrmetrics_t *reg = &pctte1interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte1interrMetrics::Publish(key, reg);
        break;
    }
    case 249:
    {
        delphi::objects::pctte1intinfometrics_t *reg = &pctte1intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte1intinfoMetrics::Publish(key, reg);
        break;
    }
    case 251:
    {
        delphi::objects::pctte2interrmetrics_t *reg = &pctte2interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte2interrMetrics::Publish(key, reg);
        break;
    }
    case 252:
    {
        delphi::objects::pctte2intinfometrics_t *reg = &pctte2intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte2intinfoMetrics::Publish(key, reg);
        break;
    }
    case 254:
    {
        delphi::objects::pctte3interrmetrics_t *reg = &pctte3interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte3interrMetrics::Publish(key, reg);
        break;
    }
    case 255:
    {
        delphi::objects::pctte3intinfometrics_t *reg = &pctte3intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte3intinfoMetrics::Publish(key, reg);
        break;
    }
    case 257:
    {
        delphi::objects::pctte4interrmetrics_t *reg = &pctte4interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte4interrMetrics::Publish(key, reg);
        break;
    }
    case 258:
    {
        delphi::objects::pctte4intinfometrics_t *reg = &pctte4intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte4intinfoMetrics::Publish(key, reg);
        break;
    }
    case 260:
    {
        delphi::objects::pctte5interrmetrics_t *reg = &pctte5interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte5interrMetrics::Publish(key, reg);
        break;
    }
    case 261:
    {
        delphi::objects::pctte5intinfometrics_t *reg = &pctte5intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte5intinfoMetrics::Publish(key, reg);
        break;
    }
    case 263:
    {
        delphi::objects::pctte6interrmetrics_t *reg = &pctte6interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte6interrMetrics::Publish(key, reg);
        break;
    }
    case 264:
    {
        delphi::objects::pctte6intinfometrics_t *reg = &pctte6intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte6intinfoMetrics::Publish(key, reg);
        break;
    }
    case 266:
    {
        delphi::objects::pctte7interrmetrics_t *reg = &pctte7interrmetrics;
        switch (field_id) {
        case 2:
            reg->miss_sop++;
            break;
        case 3:
            reg->miss_eop++;
            break;
        case 4:
            reg->phv_max_size++;
            break;
        case 5:
            reg->spurious_axi_rsp++;
            break;
        case 6:
            reg->spurious_tcam_rsp++;
            break;
        case 7:
            reg->te2mpu_timeout++;
            break;
        case 8:
            reg->axi_rdrsp_err++;
            break;
        case 9:
            reg->axi_bad_read++;
            break;
        case 10:
            reg->tcam_req_idx_fifo++;
            break;
        case 11:
            reg->tcam_rsp_idx_fifo++;
            break;
        case 12:
            reg->mpu_req_idx_fifo++;
            break;
        case 13:
            reg->axi_req_idx_fifo++;
            break;
        case 14:
            reg->proc_tbl_vld_wo_proc++;
            break;
        case 15:
            reg->pend_wo_wb++;
            break;
        case 16:
            reg->pend1_wo_pend0++;
            break;
        case 17:
            reg->both_pend_down++;
            break;
        case 18:
            reg->pend_wo_proc_down++;
            break;
        case 19:
            reg->both_pend_went_up++;
            break;
        case 20:
            reg->loaded_but_no_proc++;
            break;
        case 21:
            reg->loaded_but_no_proc_tbl_vld++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte7interrMetrics::Publish(key, reg);
        break;
    }
    case 267:
    {
        delphi::objects::pctte7intinfometrics_t *reg = &pctte7intinfometrics;
        switch (field_id) {
        case 2:
            reg->profile_cam_hit0++;
            break;
        case 3:
            reg->profile_cam_hit1++;
            break;
        case 4:
            reg->profile_cam_hit2++;
            break;
        case 5:
            reg->profile_cam_hit3++;
            break;
        case 6:
            reg->profile_cam_hit4++;
            break;
        case 7:
            reg->profile_cam_hit5++;
            break;
        case 8:
            reg->profile_cam_hit6++;
            break;
        case 9:
            reg->profile_cam_hit7++;
            break;
        case 10:
            reg->profile_cam_hit8++;
            break;
        case 11:
            reg->profile_cam_hit9++;
            break;
        case 12:
            reg->profile_cam_hit10++;
            break;
        case 13:
            reg->profile_cam_hit11++;
            break;
        case 14:
            reg->profile_cam_hit12++;
            break;
        case 15:
            reg->profile_cam_hit13++;
            break;
        case 16:
            reg->profile_cam_hit14++;
            break;
        case 17:
            reg->profile_cam_hit15++;
            break;
        case 18:
            reg->profile_cam_miss++;
            break;
        default:
            break;
        }
        delphi::objects::Pctte7intinfoMetrics::Publish(key, reg);
        break;
    }
    case 269:
    {
        delphi::objects::pctmpu0interrmetrics_t *reg = &pctmpu0interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu0interrMetrics::Publish(key, reg);
        break;
    }
    case 270:
    {
        delphi::objects::pctmpu0intinfometrics_t *reg = &pctmpu0intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu0intinfoMetrics::Publish(key, reg);
        break;
    }
    case 272:
    {
        delphi::objects::pctmpu1interrmetrics_t *reg = &pctmpu1interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu1interrMetrics::Publish(key, reg);
        break;
    }
    case 273:
    {
        delphi::objects::pctmpu1intinfometrics_t *reg = &pctmpu1intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu1intinfoMetrics::Publish(key, reg);
        break;
    }
    case 275:
    {
        delphi::objects::pctmpu2interrmetrics_t *reg = &pctmpu2interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu2interrMetrics::Publish(key, reg);
        break;
    }
    case 276:
    {
        delphi::objects::pctmpu2intinfometrics_t *reg = &pctmpu2intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu2intinfoMetrics::Publish(key, reg);
        break;
    }
    case 278:
    {
        delphi::objects::pctmpu3interrmetrics_t *reg = &pctmpu3interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu3interrMetrics::Publish(key, reg);
        break;
    }
    case 279:
    {
        delphi::objects::pctmpu3intinfometrics_t *reg = &pctmpu3intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu3intinfoMetrics::Publish(key, reg);
        break;
    }
    case 281:
    {
        delphi::objects::pctmpu4interrmetrics_t *reg = &pctmpu4interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu4interrMetrics::Publish(key, reg);
        break;
    }
    case 282:
    {
        delphi::objects::pctmpu4intinfometrics_t *reg = &pctmpu4intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu4intinfoMetrics::Publish(key, reg);
        break;
    }
    case 284:
    {
        delphi::objects::pctmpu5interrmetrics_t *reg = &pctmpu5interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu5interrMetrics::Publish(key, reg);
        break;
    }
    case 285:
    {
        delphi::objects::pctmpu5intinfometrics_t *reg = &pctmpu5intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu5intinfoMetrics::Publish(key, reg);
        break;
    }
    case 287:
    {
        delphi::objects::pctmpu6interrmetrics_t *reg = &pctmpu6interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu6interrMetrics::Publish(key, reg);
        break;
    }
    case 288:
    {
        delphi::objects::pctmpu6intinfometrics_t *reg = &pctmpu6intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu6intinfoMetrics::Publish(key, reg);
        break;
    }
    case 290:
    {
        delphi::objects::pctmpu7interrmetrics_t *reg = &pctmpu7interrmetrics;
        switch (field_id) {
        case 2:
            reg->results_mismatch++;
            break;
        case 3:
            reg->sdp_mem_uncorrectable++;
            break;
        case 4:
            reg->sdp_mem_correctable++;
            break;
        case 5:
            reg->illegal_op_0++;
            break;
        case 6:
            reg->illegal_op_1++;
            break;
        case 7:
            reg->illegal_op_2++;
            break;
        case 8:
            reg->illegal_op_3++;
            break;
        case 9:
            reg->max_inst_0++;
            break;
        case 10:
            reg->max_inst_1++;
            break;
        case 11:
            reg->max_inst_2++;
            break;
        case 12:
            reg->max_inst_3++;
            break;
        case 13:
            reg->phvwr_0++;
            break;
        case 14:
            reg->phvwr_1++;
            break;
        case 15:
            reg->phvwr_2++;
            break;
        case 16:
            reg->phvwr_3++;
            break;
        case 17:
            reg->write_err_0++;
            break;
        case 18:
            reg->write_err_1++;
            break;
        case 19:
            reg->write_err_2++;
            break;
        case 20:
            reg->write_err_3++;
            break;
        case 21:
            reg->cache_axi_0++;
            break;
        case 22:
            reg->cache_axi_1++;
            break;
        case 23:
            reg->cache_axi_2++;
            break;
        case 24:
            reg->cache_axi_3++;
            break;
        case 25:
            reg->cache_parity_0++;
            break;
        case 26:
            reg->cache_parity_1++;
            break;
        case 27:
            reg->cache_parity_2++;
            break;
        case 28:
            reg->cache_parity_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu7interrMetrics::Publish(key, reg);
        break;
    }
    case 291:
    {
        delphi::objects::pctmpu7intinfometrics_t *reg = &pctmpu7intinfometrics;
        switch (field_id) {
        case 2:
            reg->trace_full_0++;
            break;
        case 3:
            reg->trace_full_1++;
            break;
        case 4:
            reg->trace_full_2++;
            break;
        case 5:
            reg->trace_full_3++;
            break;
        case 6:
            reg->mpu_stop_0++;
            break;
        case 7:
            reg->mpu_stop_1++;
            break;
        case 8:
            reg->mpu_stop_2++;
            break;
        case 9:
            reg->mpu_stop_3++;
            break;
        default:
            break;
        }
        delphi::objects::Pctmpu7intinfoMetrics::Publish(key, reg);
        break;
    }
    case 293:
    {
        delphi::objects::pbpbcinteccfc0metrics_t *reg = &pbpbcinteccfc0metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcinteccfc0Metrics::Publish(key, reg);
        break;
    }
    case 294:
    {
        delphi::objects::pbpbcinteccll0metrics_t *reg = &pbpbcinteccll0metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcinteccll0Metrics::Publish(key, reg);
        break;
    }
    case 295:
    {
        delphi::objects::pbpbcinteccdesc0metrics_t *reg = &pbpbcinteccdesc0metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcinteccdesc0Metrics::Publish(key, reg);
        break;
    }
    case 296:
    {
        delphi::objects::pbpbcinteccfc1metrics_t *reg = &pbpbcinteccfc1metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcinteccfc1Metrics::Publish(key, reg);
        break;
    }
    case 297:
    {
        delphi::objects::pbpbcinteccll1metrics_t *reg = &pbpbcinteccll1metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcinteccll1Metrics::Publish(key, reg);
        break;
    }
    case 298:
    {
        delphi::objects::pbpbcinteccdesc1metrics_t *reg = &pbpbcinteccdesc1metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcinteccdesc1Metrics::Publish(key, reg);
        break;
    }
    case 299:
    {
        delphi::objects::pbpbcintwrite0metrics_t *reg = &pbpbcintwrite0metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite0Metrics::Publish(key, reg);
        break;
    }
    case 300:
    {
        delphi::objects::pbpbcintwrite1metrics_t *reg = &pbpbcintwrite1metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite1Metrics::Publish(key, reg);
        break;
    }
    case 301:
    {
        delphi::objects::pbpbcintwrite2metrics_t *reg = &pbpbcintwrite2metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite2Metrics::Publish(key, reg);
        break;
    }
    case 302:
    {
        delphi::objects::pbpbcintwrite3metrics_t *reg = &pbpbcintwrite3metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite3Metrics::Publish(key, reg);
        break;
    }
    case 303:
    {
        delphi::objects::pbpbcintwrite4metrics_t *reg = &pbpbcintwrite4metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite4Metrics::Publish(key, reg);
        break;
    }
    case 304:
    {
        delphi::objects::pbpbcintwrite5metrics_t *reg = &pbpbcintwrite5metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite5Metrics::Publish(key, reg);
        break;
    }
    case 305:
    {
        delphi::objects::pbpbcintwrite6metrics_t *reg = &pbpbcintwrite6metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite6Metrics::Publish(key, reg);
        break;
    }
    case 306:
    {
        delphi::objects::pbpbcintwrite7metrics_t *reg = &pbpbcintwrite7metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite7Metrics::Publish(key, reg);
        break;
    }
    case 307:
    {
        delphi::objects::pbpbcintwrite8metrics_t *reg = &pbpbcintwrite8metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite8Metrics::Publish(key, reg);
        break;
    }
    case 308:
    {
        delphi::objects::pbpbcintwrite9metrics_t *reg = &pbpbcintwrite9metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite9Metrics::Publish(key, reg);
        break;
    }
    case 309:
    {
        delphi::objects::pbpbcintwrite10metrics_t *reg = &pbpbcintwrite10metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite10Metrics::Publish(key, reg);
        break;
    }
    case 310:
    {
        delphi::objects::pbpbcintwrite11metrics_t *reg = &pbpbcintwrite11metrics;
        switch (field_id) {
        case 2:
            reg->out_of_cells++;
            break;
        case 3:
            reg->out_of_credit++;
            break;
        case 4:
            reg->port_disabled++;
            break;
        case 5:
            reg->truncation++;
            break;
        case 6:
            reg->intrinsic_drop++;
            break;
        case 7:
            reg->out_of_cells1++;
            break;
        case 8:
            reg->enq_err++;
            break;
        case 9:
            reg->tail_drop_cpu++;
            break;
        case 10:
            reg->tail_drop_span++;
            break;
        case 11:
            reg->min_size_viol++;
            break;
        case 12:
            reg->port_range++;
            break;
        case 13:
            reg->credit_growth_error++;
            break;
        case 14:
            reg->oq_range++;
            break;
        case 15:
            reg->xoff_timeout++;
            break;
        default:
            break;
        }
        delphi::objects::Pbpbcintwrite11Metrics::Publish(key, reg);
        break;
    }
    case 311:
    {
        delphi::objects::pbpbcinteccrcmetrics_t *reg = &pbpbcinteccrcmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccrcMetrics::Publish(key, reg);
        break;
    }
    case 312:
    {
        delphi::objects::pbpbcinteccpackmetrics_t *reg = &pbpbcinteccpackmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccpackMetrics::Publish(key, reg);
        break;
    }
    case 313:
    {
        delphi::objects::pbpbcinteccrwrmetrics_t *reg = &pbpbcinteccrwrmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccrwrMetrics::Publish(key, reg);
        break;
    }
    case 314:
    {
        delphi::objects::pbpbcinteccschedmetrics_t *reg = &pbpbcinteccschedmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccschedMetrics::Publish(key, reg);
        break;
    }
    case 315:
    {
        delphi::objects::pbpbcinteccsidebandmetrics_t *reg = &pbpbcinteccsidebandmetrics;
        switch (field_id) {
        case 2:
            reg->pck_uncorrectable++;
            break;
        case 3:
            reg->pck_correctable++;
            break;
        case 4:
            reg->rwr_uncorrectable++;
            break;
        case 5:
            reg->rwr_correctable++;
            break;
        case 6:
            reg->rxd_uncorrectable++;
            break;
        case 7:
            reg->rxd_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccsidebandMetrics::Publish(key, reg);
        break;
    }
    case 316:
    {
        delphi::objects::pbpbcinteccncmetrics_t *reg = &pbpbcinteccncmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccncMetrics::Publish(key, reg);
        break;
    }
    case 317:
    {
        delphi::objects::pbpbcinteccucmetrics_t *reg = &pbpbcinteccucmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccucMetrics::Publish(key, reg);
        break;
    }
    case 318:
    {
        delphi::objects::pbpbcinteccportmoninmetrics_t *reg = &pbpbcinteccportmoninmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccportmoninMetrics::Publish(key, reg);
        break;
    }
    case 319:
    {
        delphi::objects::pbpbcinteccportmonoutmetrics_t *reg = &pbpbcinteccportmonoutmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcinteccportmonoutMetrics::Publish(key, reg);
        break;
    }
    case 320:
    {
        delphi::objects::pbpbcintrplmetrics_t *reg = &pbpbcintrplmetrics;
        switch (field_id) {
        case 2:
            reg->memory_error++;
            break;
        case 3:
            reg->zero_last_error++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcintrplMetrics::Publish(key, reg);
        break;
    }
    case 321:
    {
        delphi::objects::pbpbcintcreditunderflowmetrics_t *reg = &pbpbcintcreditunderflowmetrics;
        switch (field_id) {
        case 2:
            reg->port_10++;
            break;
        case 3:
            reg->port_11++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcintcreditunderflowMetrics::Publish(key, reg);
        break;
    }
    case 322:
    {
        delphi::objects::pbpbcintpbusviolationinmetrics_t *reg = &pbpbcintpbusviolationinmetrics;
        switch (field_id) {
        case 2:
            reg->sop_sop_in_0++;
            break;
        case 3:
            reg->sop_sop_in_1++;
            break;
        case 4:
            reg->sop_sop_in_2++;
            break;
        case 5:
            reg->sop_sop_in_3++;
            break;
        case 6:
            reg->sop_sop_in_4++;
            break;
        case 7:
            reg->sop_sop_in_5++;
            break;
        case 8:
            reg->sop_sop_in_6++;
            break;
        case 9:
            reg->sop_sop_in_7++;
            break;
        case 10:
            reg->sop_sop_in_8++;
            break;
        case 11:
            reg->sop_sop_in_9++;
            break;
        case 12:
            reg->sop_sop_in_10++;
            break;
        case 13:
            reg->sop_sop_in_11++;
            break;
        case 14:
            reg->eop_eop_in_0++;
            break;
        case 15:
            reg->eop_eop_in_1++;
            break;
        case 16:
            reg->eop_eop_in_2++;
            break;
        case 17:
            reg->eop_eop_in_3++;
            break;
        case 18:
            reg->eop_eop_in_4++;
            break;
        case 19:
            reg->eop_eop_in_5++;
            break;
        case 20:
            reg->eop_eop_in_6++;
            break;
        case 21:
            reg->eop_eop_in_7++;
            break;
        case 22:
            reg->eop_eop_in_8++;
            break;
        case 23:
            reg->eop_eop_in_9++;
            break;
        case 24:
            reg->eop_eop_in_10++;
            break;
        case 25:
            reg->eop_eop_in_11++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcintpbusviolationinMetrics::Publish(key, reg);
        break;
    }
    case 323:
    {
        delphi::objects::pbpbcintpbusviolationoutmetrics_t *reg = &pbpbcintpbusviolationoutmetrics;
        switch (field_id) {
        case 2:
            reg->sop_sop_out_0++;
            break;
        case 3:
            reg->sop_sop_out_1++;
            break;
        case 4:
            reg->sop_sop_out_2++;
            break;
        case 5:
            reg->sop_sop_out_3++;
            break;
        case 6:
            reg->sop_sop_out_4++;
            break;
        case 7:
            reg->sop_sop_out_5++;
            break;
        case 8:
            reg->sop_sop_out_6++;
            break;
        case 9:
            reg->sop_sop_out_7++;
            break;
        case 10:
            reg->sop_sop_out_8++;
            break;
        case 11:
            reg->sop_sop_out_9++;
            break;
        case 12:
            reg->sop_sop_out_10++;
            break;
        case 13:
            reg->sop_sop_out_11++;
            break;
        case 14:
            reg->eop_eop_out_0++;
            break;
        case 15:
            reg->eop_eop_out_1++;
            break;
        case 16:
            reg->eop_eop_out_2++;
            break;
        case 17:
            reg->eop_eop_out_3++;
            break;
        case 18:
            reg->eop_eop_out_4++;
            break;
        case 19:
            reg->eop_eop_out_5++;
            break;
        case 20:
            reg->eop_eop_out_6++;
            break;
        case 21:
            reg->eop_eop_out_7++;
            break;
        case 22:
            reg->eop_eop_out_8++;
            break;
        case 23:
            reg->eop_eop_out_9++;
            break;
        case 24:
            reg->eop_eop_out_10++;
            break;
        case 25:
            reg->eop_eop_out_11++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbcintpbusviolationoutMetrics::Publish(key, reg);
        break;
    }
    case 325:
    {
        delphi::objects::pbpbchbmintecchbmmtumetrics_t *reg = &pbpbchbmintecchbmmtumetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbmintecchbmmtuMetrics::Publish(key, reg);
        break;
    }
    case 326:
    {
        delphi::objects::pbpbchbmintecchbmrbmetrics_t *reg = &pbpbchbmintecchbmrbmetrics;
        switch (field_id) {
        case 2:
            reg->rb_uncorrectable++;
            break;
        case 3:
            reg->rb_correctable++;
            break;
        case 4:
            reg->cdt_uncorrectable++;
            break;
        case 5:
            reg->cdt_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbmintecchbmrbMetrics::Publish(key, reg);
        break;
    }
    case 327:
    {
        delphi::objects::pbpbchbmintecchbmwbmetrics_t *reg = &pbpbchbmintecchbmwbmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbmintecchbmwbMetrics::Publish(key, reg);
        break;
    }
    case 328:
    {
        delphi::objects::pbpbchbmintecchbmhtmetrics_t *reg = &pbpbchbmintecchbmhtmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbmintecchbmhtMetrics::Publish(key, reg);
        break;
    }
    case 329:
    {
        delphi::objects::pbpbchbminthbmxoffmetrics_t *reg = &pbpbchbminthbmxoffmetrics;
        switch (field_id) {
        case 2:
            reg->timeout_0++;
            break;
        case 3:
            reg->timeout_1++;
            break;
        case 4:
            reg->timeout_2++;
            break;
        case 5:
            reg->timeout_3++;
            break;
        case 6:
            reg->timeout_4++;
            break;
        case 7:
            reg->timeout_5++;
            break;
        case 8:
            reg->timeout_6++;
            break;
        case 9:
            reg->timeout_7++;
            break;
        case 10:
            reg->timeout_8++;
            break;
        case 11:
            reg->timeout_9++;
            break;
        case 12:
            reg->timeout_10++;
            break;
        case 13:
            reg->timeout_11++;
            break;
        case 14:
            reg->timeout_12++;
            break;
        case 15:
            reg->timeout_13++;
            break;
        case 16:
            reg->timeout_14++;
            break;
        case 17:
            reg->timeout_15++;
            break;
        case 18:
            reg->timeout_16++;
            break;
        case 19:
            reg->timeout_17++;
            break;
        case 20:
            reg->timeout_18++;
            break;
        case 21:
            reg->timeout_19++;
            break;
        case 22:
            reg->timeout_20++;
            break;
        case 23:
            reg->timeout_21++;
            break;
        case 24:
            reg->timeout_22++;
            break;
        case 25:
            reg->timeout_23++;
            break;
        case 26:
            reg->timeout_24++;
            break;
        case 27:
            reg->timeout_25++;
            break;
        case 28:
            reg->timeout_26++;
            break;
        case 29:
            reg->timeout_27++;
            break;
        case 30:
            reg->timeout_28++;
            break;
        case 31:
            reg->timeout_29++;
            break;
        case 32:
            reg->timeout_30++;
            break;
        case 33:
            reg->timeout_31++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmxoffMetrics::Publish(key, reg);
        break;
    }
    case 330:
    {
        delphi::objects::pbpbchbminthbmpbusviolationinmetrics_t *reg = &pbpbchbminthbmpbusviolationinmetrics;
        switch (field_id) {
        case 2:
            reg->sop_sop_in_0++;
            break;
        case 3:
            reg->sop_sop_in_1++;
            break;
        case 4:
            reg->sop_sop_in_2++;
            break;
        case 5:
            reg->sop_sop_in_3++;
            break;
        case 6:
            reg->sop_sop_in_4++;
            break;
        case 7:
            reg->sop_sop_in_5++;
            break;
        case 8:
            reg->sop_sop_in_6++;
            break;
        case 9:
            reg->sop_sop_in_7++;
            break;
        case 10:
            reg->sop_sop_in_8++;
            break;
        case 11:
            reg->sop_sop_in_9++;
            break;
        case 12:
            reg->eop_eop_in_0++;
            break;
        case 13:
            reg->eop_eop_in_1++;
            break;
        case 14:
            reg->eop_eop_in_2++;
            break;
        case 15:
            reg->eop_eop_in_3++;
            break;
        case 16:
            reg->eop_eop_in_4++;
            break;
        case 17:
            reg->eop_eop_in_5++;
            break;
        case 18:
            reg->eop_eop_in_6++;
            break;
        case 19:
            reg->eop_eop_in_7++;
            break;
        case 20:
            reg->eop_eop_in_8++;
            break;
        case 21:
            reg->eop_eop_in_9++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmpbusviolationinMetrics::Publish(key, reg);
        break;
    }
    case 331:
    {
        delphi::objects::pbpbchbminthbmpbusviolationoutmetrics_t *reg = &pbpbchbminthbmpbusviolationoutmetrics;
        switch (field_id) {
        case 2:
            reg->sop_sop_out_0++;
            break;
        case 3:
            reg->sop_sop_out_1++;
            break;
        case 4:
            reg->sop_sop_out_2++;
            break;
        case 5:
            reg->sop_sop_out_3++;
            break;
        case 6:
            reg->sop_sop_out_4++;
            break;
        case 7:
            reg->sop_sop_out_5++;
            break;
        case 8:
            reg->sop_sop_out_6++;
            break;
        case 9:
            reg->sop_sop_out_7++;
            break;
        case 10:
            reg->sop_sop_out_8++;
            break;
        case 11:
            reg->sop_sop_out_9++;
            break;
        case 12:
            reg->eop_eop_out_0++;
            break;
        case 13:
            reg->eop_eop_out_1++;
            break;
        case 14:
            reg->eop_eop_out_2++;
            break;
        case 15:
            reg->eop_eop_out_3++;
            break;
        case 16:
            reg->eop_eop_out_4++;
            break;
        case 17:
            reg->eop_eop_out_5++;
            break;
        case 18:
            reg->eop_eop_out_6++;
            break;
        case 19:
            reg->eop_eop_out_7++;
            break;
        case 20:
            reg->eop_eop_out_8++;
            break;
        case 21:
            reg->eop_eop_out_9++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmpbusviolationoutMetrics::Publish(key, reg);
        break;
    }
    case 332:
    {
        delphi::objects::pbpbchbminthbmdropmetrics_t *reg = &pbpbchbminthbmdropmetrics;
        switch (field_id) {
        case 2:
            reg->occupancy_0++;
            break;
        case 3:
            reg->occupancy_1++;
            break;
        case 4:
            reg->occupancy_2++;
            break;
        case 5:
            reg->occupancy_3++;
            break;
        case 6:
            reg->occupancy_4++;
            break;
        case 7:
            reg->occupancy_5++;
            break;
        case 8:
            reg->occupancy_6++;
            break;
        case 9:
            reg->occupancy_7++;
            break;
        case 10:
            reg->occupancy_8++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmdropMetrics::Publish(key, reg);
        break;
    }
    case 333:
    {
        delphi::objects::pbpbchbminthbmstopmetrics_t *reg = &pbpbchbminthbmstopmetrics;
        switch (field_id) {
        case 2:
            reg->occupancy_9++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmstopMetrics::Publish(key, reg);
        break;
    }
    case 334:
    {
        delphi::objects::pbpbchbminthbmaxierrrspmetrics_t *reg = &pbpbchbminthbmaxierrrspmetrics;
        switch (field_id) {
        case 2:
            reg->ctrl++;
            break;
        case 3:
            reg->pyld++;
            break;
        case 4:
            reg->r2a++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmaxierrrspMetrics::Publish(key, reg);
        break;
    }
    case 335:
    {
        delphi::objects::pbpbchbminthbmdropemergencymetrics_t *reg = &pbpbchbminthbmdropemergencymetrics;
        switch (field_id) {
        case 2:
            reg->stop_0++;
            break;
        case 3:
            reg->stop_1++;
            break;
        case 4:
            reg->stop_2++;
            break;
        case 5:
            reg->stop_3++;
            break;
        case 6:
            reg->stop_4++;
            break;
        case 7:
            reg->stop_5++;
            break;
        case 8:
            reg->stop_6++;
            break;
        case 9:
            reg->stop_7++;
            break;
        case 10:
            reg->stop_8++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmdropemergencyMetrics::Publish(key, reg);
        break;
    }
    case 336:
    {
        delphi::objects::pbpbchbminthbmdropwriteackmetrics_t *reg = &pbpbchbminthbmdropwriteackmetrics;
        switch (field_id) {
        case 2:
            reg->filling_up_0++;
            break;
        case 3:
            reg->filling_up_1++;
            break;
        case 4:
            reg->filling_up_2++;
            break;
        case 5:
            reg->filling_up_3++;
            break;
        case 6:
            reg->filling_up_4++;
            break;
        case 7:
            reg->filling_up_5++;
            break;
        case 8:
            reg->filling_up_6++;
            break;
        case 9:
            reg->filling_up_7++;
            break;
        case 10:
            reg->filling_up_8++;
            break;
        case 11:
            reg->full_0++;
            break;
        case 12:
            reg->full_1++;
            break;
        case 13:
            reg->full_2++;
            break;
        case 14:
            reg->full_3++;
            break;
        case 15:
            reg->full_4++;
            break;
        case 16:
            reg->full_5++;
            break;
        case 17:
            reg->full_6++;
            break;
        case 18:
            reg->full_7++;
            break;
        case 19:
            reg->full_8++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmdropwriteackMetrics::Publish(key, reg);
        break;
    }
    case 337:
    {
        delphi::objects::pbpbchbminthbmdropctrlmetrics_t *reg = &pbpbchbminthbmdropctrlmetrics;
        switch (field_id) {
        case 2:
            reg->full_0++;
            break;
        case 3:
            reg->full_1++;
            break;
        case 4:
            reg->full_2++;
            break;
        case 5:
            reg->full_3++;
            break;
        case 6:
            reg->full_4++;
            break;
        case 7:
            reg->full_5++;
            break;
        case 8:
            reg->full_6++;
            break;
        case 9:
            reg->full_7++;
            break;
        case 10:
            reg->full_8++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmdropctrlMetrics::Publish(key, reg);
        break;
    }
    case 338:
    {
        delphi::objects::pbpbchbminthbmdropthresholdmetrics_t *reg = &pbpbchbminthbmdropthresholdmetrics;
        switch (field_id) {
        case 2:
            reg->crossed_0++;
            break;
        case 3:
            reg->crossed_1++;
            break;
        case 4:
            reg->crossed_2++;
            break;
        case 5:
            reg->crossed_3++;
            break;
        case 6:
            reg->crossed_4++;
            break;
        case 7:
            reg->crossed_5++;
            break;
        case 8:
            reg->crossed_6++;
            break;
        case 9:
            reg->crossed_7++;
            break;
        case 10:
            reg->crossed_8++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmdropthresholdMetrics::Publish(key, reg);
        break;
    }
    case 339:
    {
        delphi::objects::pbpbchbminthbmtruncatenometrics_t *reg = &pbpbchbminthbmtruncatenometrics;
        switch (field_id) {
        case 2:
            reg->drop_0++;
            break;
        case 3:
            reg->drop_1++;
            break;
        case 4:
            reg->drop_2++;
            break;
        case 5:
            reg->drop_3++;
            break;
        case 6:
            reg->drop_4++;
            break;
        case 7:
            reg->drop_5++;
            break;
        case 8:
            reg->drop_6++;
            break;
        case 9:
            reg->drop_7++;
            break;
        case 10:
            reg->drop_8++;
            break;
        default:
            break;
        }
        delphi::objects::PbpbchbminthbmtruncatenoMetrics::Publish(key, reg);
        break;
    }
    case 341:
    {
        delphi::objects::pmpbmintecccol0metrics_t *reg = &pmpbmintecccol0metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pmpbmintecccol0Metrics::Publish(key, reg);
        break;
    }
    case 342:
    {
        delphi::objects::pmpbmintecccol1metrics_t *reg = &pmpbmintecccol1metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pmpbmintecccol1Metrics::Publish(key, reg);
        break;
    }
    case 343:
    {
        delphi::objects::pmpbmintecccol2metrics_t *reg = &pmpbmintecccol2metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pmpbmintecccol2Metrics::Publish(key, reg);
        break;
    }
    case 344:
    {
        delphi::objects::pmpbmintecccol3metrics_t *reg = &pmpbmintecccol3metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pmpbmintecccol3Metrics::Publish(key, reg);
        break;
    }
    case 345:
    {
        delphi::objects::pmpbmintecccol4metrics_t *reg = &pmpbmintecccol4metrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Pmpbmintecccol4Metrics::Publish(key, reg);
        break;
    }
    case 347:
    {
        delphi::objects::dbwaintlifqstatemapmetrics_t *reg = &dbwaintlifqstatemapmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_uncorrectable++;
            break;
        case 3:
            reg->ecc_correctable++;
            break;
        case 4:
            reg->qid_invalid++;
            break;
        default:
            break;
        }
        delphi::objects::DbwaintlifqstatemapMetrics::Publish(key, reg);
        break;
    }
    case 348:
    {
        delphi::objects::dbwaintdbmetrics_t *reg = &dbwaintdbmetrics;
        switch (field_id) {
        case 2:
            reg->db_cam_conflict++;
            break;
        case 3:
            reg->db_pid_chk_fail++;
            break;
        case 4:
            reg->db_qid_overflow++;
            break;
        case 5:
            reg->host_ring_access_err++;
            break;
        case 6:
            reg->total_ring_access_err++;
            break;
        case 7:
            reg->rresp_err++;
            break;
        case 8:
            reg->bresp_err++;
            break;
        default:
            break;
        }
        delphi::objects::DbwaintdbMetrics::Publish(key, reg);
        break;
    }
    case 350:
    {
        delphi::objects::ssipicsintpicsmetrics_t *reg = &ssipicsintpicsmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable_ecc++;
            break;
        case 3:
            reg->correctable_ecc++;
            break;
        case 4:
            reg->too_many_rl_sch_error++;
            break;
        case 5:
            reg->picc++;
            break;
        default:
            break;
        }
        delphi::objects::SsipicsintpicsMetrics::Publish(key, reg);
        break;
    }
    case 351:
    {
        delphi::objects::ssipicsintbadaddrmetrics_t *reg = &ssipicsintbadaddrmetrics;
        switch (field_id) {
        case 2:
            reg->rdreq0_bad_addr++;
            break;
        case 3:
            reg->wrreq0_bad_addr++;
            break;
        case 4:
            reg->rdreq1_bad_addr++;
            break;
        case 5:
            reg->wrreq1_bad_addr++;
            break;
        case 6:
            reg->rdreq2_bad_addr++;
            break;
        case 7:
            reg->wrreq2_bad_addr++;
            break;
        case 8:
            reg->rdreq3_bad_addr++;
            break;
        case 9:
            reg->wrreq3_bad_addr++;
            break;
        case 10:
            reg->rdreq4_bad_addr++;
            break;
        case 11:
            reg->wrreq4_bad_addr++;
            break;
        case 12:
            reg->rdreq5_bad_addr++;
            break;
        case 13:
            reg->wrreq5_bad_addr++;
            break;
        case 14:
            reg->rdreq6_bad_addr++;
            break;
        case 15:
            reg->wrreq6_bad_addr++;
            break;
        case 16:
            reg->rdreq7_bad_addr++;
            break;
        case 17:
            reg->wrreq7_bad_addr++;
            break;
        case 18:
            reg->cpu_bad_addr++;
            break;
        case 19:
            reg->bg_bad_addr++;
            break;
        default:
            break;
        }
        delphi::objects::SsipicsintbadaddrMetrics::Publish(key, reg);
        break;
    }
    case 352:
    {
        delphi::objects::ssipicsintbgmetrics_t *reg = &ssipicsintbgmetrics;
        switch (field_id) {
        case 2:
            reg->unfinished_bg0++;
            break;
        case 3:
            reg->unfinished_bg1++;
            break;
        case 4:
            reg->unfinished_bg2++;
            break;
        case 5:
            reg->unfinished_bg3++;
            break;
        case 6:
            reg->unfinished_bg4++;
            break;
        case 7:
            reg->unfinished_bg5++;
            break;
        case 8:
            reg->unfinished_bg6++;
            break;
        case 9:
            reg->unfinished_bg7++;
            break;
        case 10:
            reg->unfinished_bg8++;
            break;
        case 11:
            reg->unfinished_bg9++;
            break;
        case 12:
            reg->unfinished_bg10++;
            break;
        case 13:
            reg->unfinished_bg11++;
            break;
        case 14:
            reg->unfinished_bg12++;
            break;
        case 15:
            reg->unfinished_bg13++;
            break;
        case 16:
            reg->unfinished_bg14++;
            break;
        case 17:
            reg->unfinished_bg15++;
            break;
        default:
            break;
        }
        delphi::objects::SsipicsintbgMetrics::Publish(key, reg);
        break;
    }
    case 354:
    {
        delphi::objects::ssipicspiccintpiccmetrics_t *reg = &ssipicspiccintpiccmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable_ecc++;
            break;
        case 3:
            reg->correctable_ecc++;
            break;
        case 4:
            reg->cache_stg_awlen_err++;
            break;
        case 5:
            reg->cache_hbm_rresp_slverr++;
            break;
        case 6:
            reg->cache_hbm_rresp_decerr++;
            break;
        case 7:
            reg->cache_hbm_bresp_slverr++;
            break;
        case 8:
            reg->cache_hbm_bresp_decerr++;
            break;
        default:
            break;
        }
        delphi::objects::SsipicspiccintpiccMetrics::Publish(key, reg);
        break;
    }
    case 356:
    {
        delphi::objects::ssepicsintpicsmetrics_t *reg = &ssepicsintpicsmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable_ecc++;
            break;
        case 3:
            reg->correctable_ecc++;
            break;
        case 4:
            reg->too_many_rl_sch_error++;
            break;
        case 5:
            reg->picc++;
            break;
        default:
            break;
        }
        delphi::objects::SsepicsintpicsMetrics::Publish(key, reg);
        break;
    }
    case 357:
    {
        delphi::objects::ssepicsintbadaddrmetrics_t *reg = &ssepicsintbadaddrmetrics;
        switch (field_id) {
        case 2:
            reg->rdreq0_bad_addr++;
            break;
        case 3:
            reg->wrreq0_bad_addr++;
            break;
        case 4:
            reg->rdreq1_bad_addr++;
            break;
        case 5:
            reg->wrreq1_bad_addr++;
            break;
        case 6:
            reg->rdreq2_bad_addr++;
            break;
        case 7:
            reg->wrreq2_bad_addr++;
            break;
        case 8:
            reg->rdreq3_bad_addr++;
            break;
        case 9:
            reg->wrreq3_bad_addr++;
            break;
        case 10:
            reg->rdreq4_bad_addr++;
            break;
        case 11:
            reg->wrreq4_bad_addr++;
            break;
        case 12:
            reg->rdreq5_bad_addr++;
            break;
        case 13:
            reg->wrreq5_bad_addr++;
            break;
        case 14:
            reg->rdreq6_bad_addr++;
            break;
        case 15:
            reg->wrreq6_bad_addr++;
            break;
        case 16:
            reg->rdreq7_bad_addr++;
            break;
        case 17:
            reg->wrreq7_bad_addr++;
            break;
        case 18:
            reg->cpu_bad_addr++;
            break;
        case 19:
            reg->bg_bad_addr++;
            break;
        default:
            break;
        }
        delphi::objects::SsepicsintbadaddrMetrics::Publish(key, reg);
        break;
    }
    case 358:
    {
        delphi::objects::ssepicsintbgmetrics_t *reg = &ssepicsintbgmetrics;
        switch (field_id) {
        case 2:
            reg->unfinished_bg0++;
            break;
        case 3:
            reg->unfinished_bg1++;
            break;
        case 4:
            reg->unfinished_bg2++;
            break;
        case 5:
            reg->unfinished_bg3++;
            break;
        case 6:
            reg->unfinished_bg4++;
            break;
        case 7:
            reg->unfinished_bg5++;
            break;
        case 8:
            reg->unfinished_bg6++;
            break;
        case 9:
            reg->unfinished_bg7++;
            break;
        case 10:
            reg->unfinished_bg8++;
            break;
        case 11:
            reg->unfinished_bg9++;
            break;
        case 12:
            reg->unfinished_bg10++;
            break;
        case 13:
            reg->unfinished_bg11++;
            break;
        case 14:
            reg->unfinished_bg12++;
            break;
        case 15:
            reg->unfinished_bg13++;
            break;
        case 16:
            reg->unfinished_bg14++;
            break;
        case 17:
            reg->unfinished_bg15++;
            break;
        default:
            break;
        }
        delphi::objects::SsepicsintbgMetrics::Publish(key, reg);
        break;
    }
    case 360:
    {
        delphi::objects::ssepicspiccintpiccmetrics_t *reg = &ssepicspiccintpiccmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable_ecc++;
            break;
        case 3:
            reg->correctable_ecc++;
            break;
        case 4:
            reg->cache_stg_awlen_err++;
            break;
        case 5:
            reg->cache_hbm_rresp_slverr++;
            break;
        case 6:
            reg->cache_hbm_rresp_decerr++;
            break;
        case 7:
            reg->cache_hbm_bresp_slverr++;
            break;
        case 8:
            reg->cache_hbm_bresp_decerr++;
            break;
        default:
            break;
        }
        delphi::objects::SsepicspiccintpiccMetrics::Publish(key, reg);
        break;
    }
    case 362:
    {
        delphi::objects::bxbxintmacmetrics_t *reg = &bxbxintmacmetrics;
        switch (field_id) {
        case 2:
            reg->lane_sbe++;
            break;
        case 3:
            reg->lane_dbe++;
            break;
        case 4:
            reg->xdmac10_intr++;
            break;
        case 5:
            reg->xdmac10_pslverr++;
            break;
        case 6:
            reg->bxpb_pbus_drdy++;
            break;
        case 7:
            reg->rx_missing_sof++;
            break;
        case 8:
            reg->rx_missing_eof++;
            break;
        case 9:
            reg->rx_timeout_err++;
            break;
        case 10:
            reg->rx_min_size_err++;
            break;
        default:
            break;
        }
        delphi::objects::BxbxintmacMetrics::Publish(key, reg);
        break;
    }
    case 364:
    {
        delphi::objects::mdhensintipcoremetrics_t *reg = &mdhensintipcoremetrics;
        switch (field_id) {
        case 2:
            reg->xts_enc++;
            break;
        case 3:
            reg->xts++;
            break;
        case 4:
            reg->gcm0++;
            break;
        case 5:
            reg->gcm1++;
            break;
        case 6:
            reg->drbg++;
            break;
        case 7:
            reg->pk++;
            break;
        case 8:
            reg->cp++;
            break;
        case 9:
            reg->dc++;
            break;
        default:
            break;
        }
        delphi::objects::MdhensintipcoreMetrics::Publish(key, reg);
        break;
    }
    case 365:
    {
        delphi::objects::mdhensintpkeccmetrics_t *reg = &mdhensintpkeccmetrics;
        switch (field_id) {
        case 2:
            reg->correctable_err++;
            break;
        case 3:
            reg->uncorrectable_err++;
            break;
        default:
            break;
        }
        delphi::objects::MdhensintpkeccMetrics::Publish(key, reg);
        break;
    }
    case 366:
    {
        delphi::objects::mdhensintdrbgintrameccmetrics_t *reg = &mdhensintdrbgintrameccmetrics;
        switch (field_id) {
        case 2:
            reg->correctable_err++;
            break;
        case 3:
            reg->uncorrectable_err++;
            break;
        default:
            break;
        }
        delphi::objects::MdhensintdrbgintrameccMetrics::Publish(key, reg);
        break;
    }
    case 367:
    {
        delphi::objects::mdhensintdrbgcryptorameccmetrics_t *reg = &mdhensintdrbgcryptorameccmetrics;
        switch (field_id) {
        case 2:
            reg->correctable_err++;
            break;
        case 3:
            reg->uncorrectable_err++;
            break;
        default:
            break;
        }
        delphi::objects::MdhensintdrbgcryptorameccMetrics::Publish(key, reg);
        break;
    }
    case 368:
    {
        delphi::objects::mdhensintaxierrmetrics_t *reg = &mdhensintaxierrmetrics;
        switch (field_id) {
        case 2:
            reg->wrsp_err++;
            break;
        case 3:
            reg->rrsp_err++;
            break;
        default:
            break;
        }
        delphi::objects::MdhensintaxierrMetrics::Publish(key, reg);
        break;
    }
    case 370:
    {
        delphi::objects::tpcpicsintpicsmetrics_t *reg = &tpcpicsintpicsmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable_ecc++;
            break;
        case 3:
            reg->correctable_ecc++;
            break;
        case 4:
            reg->too_many_rl_sch_error++;
            break;
        case 5:
            reg->picc++;
            break;
        default:
            break;
        }
        delphi::objects::TpcpicsintpicsMetrics::Publish(key, reg);
        break;
    }
    case 371:
    {
        delphi::objects::tpcpicsintbadaddrmetrics_t *reg = &tpcpicsintbadaddrmetrics;
        switch (field_id) {
        case 2:
            reg->rdreq0_bad_addr++;
            break;
        case 3:
            reg->wrreq0_bad_addr++;
            break;
        case 4:
            reg->rdreq1_bad_addr++;
            break;
        case 5:
            reg->wrreq1_bad_addr++;
            break;
        case 6:
            reg->rdreq2_bad_addr++;
            break;
        case 7:
            reg->wrreq2_bad_addr++;
            break;
        case 8:
            reg->rdreq3_bad_addr++;
            break;
        case 9:
            reg->wrreq3_bad_addr++;
            break;
        case 10:
            reg->rdreq4_bad_addr++;
            break;
        case 11:
            reg->wrreq4_bad_addr++;
            break;
        case 12:
            reg->rdreq5_bad_addr++;
            break;
        case 13:
            reg->wrreq5_bad_addr++;
            break;
        case 14:
            reg->rdreq6_bad_addr++;
            break;
        case 15:
            reg->wrreq6_bad_addr++;
            break;
        case 16:
            reg->rdreq7_bad_addr++;
            break;
        case 17:
            reg->wrreq7_bad_addr++;
            break;
        case 18:
            reg->cpu_bad_addr++;
            break;
        case 19:
            reg->bg_bad_addr++;
            break;
        default:
            break;
        }
        delphi::objects::TpcpicsintbadaddrMetrics::Publish(key, reg);
        break;
    }
    case 372:
    {
        delphi::objects::tpcpicsintbgmetrics_t *reg = &tpcpicsintbgmetrics;
        switch (field_id) {
        case 2:
            reg->unfinished_bg0++;
            break;
        case 3:
            reg->unfinished_bg1++;
            break;
        case 4:
            reg->unfinished_bg2++;
            break;
        case 5:
            reg->unfinished_bg3++;
            break;
        case 6:
            reg->unfinished_bg4++;
            break;
        case 7:
            reg->unfinished_bg5++;
            break;
        case 8:
            reg->unfinished_bg6++;
            break;
        case 9:
            reg->unfinished_bg7++;
            break;
        case 10:
            reg->unfinished_bg8++;
            break;
        case 11:
            reg->unfinished_bg9++;
            break;
        case 12:
            reg->unfinished_bg10++;
            break;
        case 13:
            reg->unfinished_bg11++;
            break;
        case 14:
            reg->unfinished_bg12++;
            break;
        case 15:
            reg->unfinished_bg13++;
            break;
        case 16:
            reg->unfinished_bg14++;
            break;
        case 17:
            reg->unfinished_bg15++;
            break;
        default:
            break;
        }
        delphi::objects::TpcpicsintbgMetrics::Publish(key, reg);
        break;
    }
    case 374:
    {
        delphi::objects::tpcpicspiccintpiccmetrics_t *reg = &tpcpicspiccintpiccmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable_ecc++;
            break;
        case 3:
            reg->correctable_ecc++;
            break;
        case 4:
            reg->cache_stg_awlen_err++;
            break;
        case 5:
            reg->cache_hbm_rresp_slverr++;
            break;
        case 6:
            reg->cache_hbm_rresp_decerr++;
            break;
        case 7:
            reg->cache_hbm_bresp_slverr++;
            break;
        case 8:
            reg->cache_hbm_bresp_decerr++;
            break;
        default:
            break;
        }
        delphi::objects::TpcpicspiccintpiccMetrics::Publish(key, reg);
        break;
    }
    case 376:
    {
        delphi::objects::dprdpr0intreg1metrics_t *reg = &dprdpr0intreg1metrics;
        switch (field_id) {
        case 2:
            reg->err_phv_sop_no_eop++;
            break;
        case 3:
            reg->err_phv_eop_no_sop++;
            break;
        case 4:
            reg->err_ohi_sop_no_eop++;
            break;
        case 5:
            reg->err_ohi_eop_no_sop++;
            break;
        case 6:
            reg->err_pktin_sop_no_eop++;
            break;
        case 7:
            reg->err_pktin_eop_no_sop++;
            break;
        case 8:
            reg->err_csum_offset_gt_pkt_size_4++;
            break;
        case 9:
            reg->err_csum_offset_gt_pkt_size_3++;
            break;
        case 10:
            reg->err_csum_offset_gt_pkt_size_2++;
            break;
        case 11:
            reg->err_csum_offset_gt_pkt_size_1++;
            break;
        case 12:
            reg->err_csum_offset_gt_pkt_size_0++;
            break;
        case 13:
            reg->err_csum_phdr_offset_gt_pkt_size_4++;
            break;
        case 14:
            reg->err_csum_phdr_offset_gt_pkt_size_3++;
            break;
        case 15:
            reg->err_csum_phdr_offset_gt_pkt_size_2++;
            break;
        case 16:
            reg->err_csum_phdr_offset_gt_pkt_size_1++;
            break;
        case 17:
            reg->err_csum_phdr_offset_gt_pkt_size_0++;
            break;
        case 18:
            reg->err_csum_loc_gt_pkt_size_4++;
            break;
        case 19:
            reg->err_csum_loc_gt_pkt_size_3++;
            break;
        case 20:
            reg->err_csum_loc_gt_pkt_size_2++;
            break;
        case 21:
            reg->err_csum_loc_gt_pkt_size_1++;
            break;
        case 22:
            reg->err_csum_loc_gt_pkt_size_0++;
            break;
        case 23:
            reg->err_crc_offset_gt_pkt_size++;
            break;
        case 24:
            reg->err_crc_loc_gt_pkt_size++;
            break;
        case 25:
            reg->err_crc_mask_offset_gt_pkt_size++;
            break;
        case 26:
            reg->err_pkt_eop_early++;
            break;
        case 27:
            reg->err_ptr_ff_overflow++;
            break;
        case 28:
            reg->err_csum_ff_overflow++;
            break;
        case 29:
            reg->err_pktout_ff_overflow++;
            break;
        case 30:
            reg->err_ptr_from_cfg_overflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr0intreg1Metrics::Publish(key, reg);
        break;
    }
    case 377:
    {
        delphi::objects::dprdpr0intreg2metrics_t *reg = &dprdpr0intreg2metrics;
        switch (field_id) {
        case 2:
            reg->fieldC++;
            break;
        case 3:
            reg->fieldD++;
            break;
        case 4:
            reg->err_csum_start_gt_end_4++;
            break;
        case 5:
            reg->err_csum_start_gt_end_3++;
            break;
        case 6:
            reg->err_csum_start_gt_end_2++;
            break;
        case 7:
            reg->err_csum_start_gt_end_1++;
            break;
        case 8:
            reg->err_csum_start_gt_end_0++;
            break;
        case 9:
            reg->err_crc_start_gt_end++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr0intreg2Metrics::Publish(key, reg);
        break;
    }
    case 378:
    {
        delphi::objects::dprdpr0intsramseccmetrics_t *reg = &dprdpr0intsramseccmetrics;
        switch (field_id) {
        case 2:
            reg->dpr_pktin_fifo_uncorrectable++;
            break;
        case 3:
            reg->dpr_pktin_fifo_correctable++;
            break;
        case 4:
            reg->dpr_csum_fifo_uncorrectable++;
            break;
        case 5:
            reg->dpr_csum_fifo_correctable++;
            break;
        case 6:
            reg->dpr_phv_fifo_uncorrectable++;
            break;
        case 7:
            reg->dpr_phv_fifo_correctable++;
            break;
        case 8:
            reg->dpr_ohi_fifo_uncorrectable++;
            break;
        case 9:
            reg->dpr_ohi_fifo_correctable++;
            break;
        case 10:
            reg->dpr_ptr_fifo_uncorrectable++;
            break;
        case 11:
            reg->dpr_ptr_fifo_correctable++;
            break;
        case 12:
            reg->dpr_pktout_fifo_uncorrectable++;
            break;
        case 13:
            reg->dpr_pktout_fifo_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr0intsramseccMetrics::Publish(key, reg);
        break;
    }
    case 379:
    {
        delphi::objects::dprdpr0intfifometrics_t *reg = &dprdpr0intfifometrics;
        switch (field_id) {
        case 2:
            reg->phv_ff_ovflow++;
            break;
        case 3:
            reg->ohi_ff_ovflow++;
            break;
        case 4:
            reg->pktin_ff_ovflow++;
            break;
        case 5:
            reg->pktout_ff_undflow++;
            break;
        case 6:
            reg->csum_ff_ovflow++;
            break;
        case 7:
            reg->ptr_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr0intfifoMetrics::Publish(key, reg);
        break;
    }
    case 380:
    {
        delphi::objects::dprdpr0intflopfifo0metrics_t *reg = &dprdpr0intflopfifo0metrics;
        switch (field_id) {
        case 2:
            reg->data_mux_force_bypass_crc_flop_ff_ovflow++;
            break;
        case 3:
            reg->dpr_crc_info_flop_ff_ovflow++;
            break;
        case 4:
            reg->dpr_crc_update_info_flop_ff_ovflow++;
            break;
        case 5:
            reg->dpr_csum_info_flop_ff_ovflow++;
            break;
        case 6:
            reg->data_mux_force_bypass_csum_flop_ff_ovflow++;
            break;
        case 7:
            reg->dpr_csum_update_info_flop_ff_ovflow++;
            break;
        case 8:
            reg->ptr_early_pkt_eop_info_flop_ff_ovflow++;
            break;
        case 9:
            reg->data_mux_eop_err_flop_ff_ovflow++;
            break;
        case 10:
            reg->pktin_eop_err_flop_ff_ovflow++;
            break;
        case 11:
            reg->csum_err_flop_ff_ovflow++;
            break;
        case 12:
            reg->crc_err_flop_ff_ovflow++;
            break;
        case 13:
            reg->data_mux_drop_flop_ff_ovflow++;
            break;
        case 14:
            reg->phv_pkt_data_flop_ff_ovflow++;
            break;
        case 15:
            reg->pktout_len_cell_flop_ff_ovflow++;
            break;
        case 16:
            reg->padding_size_flop_ff_ovflow++;
            break;
        case 17:
            reg->pktin_err_flop_ff_ovflow++;
            break;
        case 18:
            reg->phv_no_data_flop_ff_ovflow++;
            break;
        case 19:
            reg->ptr_lookahaed_flop_ff_ovflow++;
            break;
        case 20:
            reg->eop_vld_flop_ff_ovflow++;
            break;
        case 21:
            reg->csum_cal_vld_flop_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr0intflopfifo0Metrics::Publish(key, reg);
        break;
    }
    case 381:
    {
        delphi::objects::dprdpr0intflopfifo1metrics_t *reg = &dprdpr0intflopfifo1metrics;
        switch (field_id) {
        case 2:
            reg->data_mux_force_bypass_crc_flop_ff_undflow++;
            break;
        case 3:
            reg->dpr_crc_info_flop_ff_undflow++;
            break;
        case 4:
            reg->dpr_crc_update_info_flop_ff_undflow++;
            break;
        case 5:
            reg->dpr_csum_info_flop_ff_undflow++;
            break;
        case 6:
            reg->data_mux_force_bypass_csum_flop_ff_undflow++;
            break;
        case 7:
            reg->dpr_csum_update_info_flop_ff_undflow++;
            break;
        case 8:
            reg->ptr_early_pkt_eop_info_flop_ff_undflow++;
            break;
        case 9:
            reg->data_mux_eop_err_flop_ff_undflow++;
            break;
        case 10:
            reg->pktin_eop_err_flop_ff_undflow++;
            break;
        case 11:
            reg->csum_err_flop_ff_undflow++;
            break;
        case 12:
            reg->crc_err_flop_ff_undflow++;
            break;
        case 13:
            reg->data_mux_drop_flop_ff_undflow++;
            break;
        case 14:
            reg->phv_pkt_data_flop_ff_undflow++;
            break;
        case 15:
            reg->pktout_len_cell_flop_ff_undflow++;
            break;
        case 16:
            reg->padding_size_flop_ff_undflow++;
            break;
        case 17:
            reg->pktin_err_flop_ff_undflow++;
            break;
        case 18:
            reg->phv_no_data_flop_ff_undflow++;
            break;
        case 19:
            reg->ptr_lookahaed_flop_ff_undflow++;
            break;
        case 20:
            reg->eop_vld_flop_ff_undflow++;
            break;
        case 21:
            reg->csum_cal_vld_flop_ff_undflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr0intflopfifo1Metrics::Publish(key, reg);
        break;
    }
    case 382:
    {
        delphi::objects::dprdpr0intsparemetrics_t *reg = &dprdpr0intsparemetrics;
        switch (field_id) {
        case 2:
            reg->spare_0++;
            break;
        case 3:
            reg->spare_1++;
            break;
        case 4:
            reg->spare_2++;
            break;
        case 5:
            reg->spare_3++;
            break;
        case 6:
            reg->spare_4++;
            break;
        case 7:
            reg->spare_5++;
            break;
        case 8:
            reg->spare_6++;
            break;
        case 9:
            reg->spare_7++;
            break;
        case 10:
            reg->spare_8++;
            break;
        case 11:
            reg->spare_9++;
            break;
        case 12:
            reg->spare_10++;
            break;
        case 13:
            reg->spare_11++;
            break;
        case 14:
            reg->spare_12++;
            break;
        case 15:
            reg->spare_13++;
            break;
        case 16:
            reg->spare_14++;
            break;
        case 17:
            reg->spare_15++;
            break;
        case 18:
            reg->spare_16++;
            break;
        case 19:
            reg->spare_17++;
            break;
        case 20:
            reg->spare_18++;
            break;
        case 21:
            reg->spare_19++;
            break;
        case 22:
            reg->spare_20++;
            break;
        case 23:
            reg->spare_21++;
            break;
        case 24:
            reg->spare_22++;
            break;
        case 25:
            reg->spare_23++;
            break;
        case 26:
            reg->spare_24++;
            break;
        case 27:
            reg->spare_25++;
            break;
        case 28:
            reg->spare_26++;
            break;
        case 29:
            reg->spare_27++;
            break;
        case 30:
            reg->spare_28++;
            break;
        case 31:
            reg->spare_29++;
            break;
        case 32:
            reg->spare_30++;
            break;
        case 33:
            reg->spare_31++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr0intspareMetrics::Publish(key, reg);
        break;
    }
    case 383:
    {
        delphi::objects::dprdpr0intcreditmetrics_t *reg = &dprdpr0intcreditmetrics;
        switch (field_id) {
        case 2:
            reg->egress_credit_ovflow++;
            break;
        case 3:
            reg->egress_credit_undflow++;
            break;
        case 4:
            reg->pktout_credit_ovflow++;
            break;
        case 5:
            reg->pktout_credit_undflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr0intcreditMetrics::Publish(key, reg);
        break;
    }
    case 385:
    {
        delphi::objects::dprdpr1intreg1metrics_t *reg = &dprdpr1intreg1metrics;
        switch (field_id) {
        case 2:
            reg->err_phv_sop_no_eop++;
            break;
        case 3:
            reg->err_phv_eop_no_sop++;
            break;
        case 4:
            reg->err_ohi_sop_no_eop++;
            break;
        case 5:
            reg->err_ohi_eop_no_sop++;
            break;
        case 6:
            reg->err_pktin_sop_no_eop++;
            break;
        case 7:
            reg->err_pktin_eop_no_sop++;
            break;
        case 8:
            reg->err_csum_offset_gt_pkt_size_4++;
            break;
        case 9:
            reg->err_csum_offset_gt_pkt_size_3++;
            break;
        case 10:
            reg->err_csum_offset_gt_pkt_size_2++;
            break;
        case 11:
            reg->err_csum_offset_gt_pkt_size_1++;
            break;
        case 12:
            reg->err_csum_offset_gt_pkt_size_0++;
            break;
        case 13:
            reg->err_csum_phdr_offset_gt_pkt_size_4++;
            break;
        case 14:
            reg->err_csum_phdr_offset_gt_pkt_size_3++;
            break;
        case 15:
            reg->err_csum_phdr_offset_gt_pkt_size_2++;
            break;
        case 16:
            reg->err_csum_phdr_offset_gt_pkt_size_1++;
            break;
        case 17:
            reg->err_csum_phdr_offset_gt_pkt_size_0++;
            break;
        case 18:
            reg->err_csum_loc_gt_pkt_size_4++;
            break;
        case 19:
            reg->err_csum_loc_gt_pkt_size_3++;
            break;
        case 20:
            reg->err_csum_loc_gt_pkt_size_2++;
            break;
        case 21:
            reg->err_csum_loc_gt_pkt_size_1++;
            break;
        case 22:
            reg->err_csum_loc_gt_pkt_size_0++;
            break;
        case 23:
            reg->err_crc_offset_gt_pkt_size++;
            break;
        case 24:
            reg->err_crc_loc_gt_pkt_size++;
            break;
        case 25:
            reg->err_crc_mask_offset_gt_pkt_size++;
            break;
        case 26:
            reg->err_pkt_eop_early++;
            break;
        case 27:
            reg->err_ptr_ff_overflow++;
            break;
        case 28:
            reg->err_csum_ff_overflow++;
            break;
        case 29:
            reg->err_pktout_ff_overflow++;
            break;
        case 30:
            reg->err_ptr_from_cfg_overflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr1intreg1Metrics::Publish(key, reg);
        break;
    }
    case 386:
    {
        delphi::objects::dprdpr1intreg2metrics_t *reg = &dprdpr1intreg2metrics;
        switch (field_id) {
        case 2:
            reg->fieldC++;
            break;
        case 3:
            reg->fieldD++;
            break;
        case 4:
            reg->err_csum_start_gt_end_4++;
            break;
        case 5:
            reg->err_csum_start_gt_end_3++;
            break;
        case 6:
            reg->err_csum_start_gt_end_2++;
            break;
        case 7:
            reg->err_csum_start_gt_end_1++;
            break;
        case 8:
            reg->err_csum_start_gt_end_0++;
            break;
        case 9:
            reg->err_crc_start_gt_end++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr1intreg2Metrics::Publish(key, reg);
        break;
    }
    case 387:
    {
        delphi::objects::dprdpr1intsramseccmetrics_t *reg = &dprdpr1intsramseccmetrics;
        switch (field_id) {
        case 2:
            reg->dpr_pktin_fifo_uncorrectable++;
            break;
        case 3:
            reg->dpr_pktin_fifo_correctable++;
            break;
        case 4:
            reg->dpr_csum_fifo_uncorrectable++;
            break;
        case 5:
            reg->dpr_csum_fifo_correctable++;
            break;
        case 6:
            reg->dpr_phv_fifo_uncorrectable++;
            break;
        case 7:
            reg->dpr_phv_fifo_correctable++;
            break;
        case 8:
            reg->dpr_ohi_fifo_uncorrectable++;
            break;
        case 9:
            reg->dpr_ohi_fifo_correctable++;
            break;
        case 10:
            reg->dpr_ptr_fifo_uncorrectable++;
            break;
        case 11:
            reg->dpr_ptr_fifo_correctable++;
            break;
        case 12:
            reg->dpr_pktout_fifo_uncorrectable++;
            break;
        case 13:
            reg->dpr_pktout_fifo_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr1intsramseccMetrics::Publish(key, reg);
        break;
    }
    case 388:
    {
        delphi::objects::dprdpr1intfifometrics_t *reg = &dprdpr1intfifometrics;
        switch (field_id) {
        case 2:
            reg->phv_ff_ovflow++;
            break;
        case 3:
            reg->ohi_ff_ovflow++;
            break;
        case 4:
            reg->pktin_ff_ovflow++;
            break;
        case 5:
            reg->pktout_ff_undflow++;
            break;
        case 6:
            reg->csum_ff_ovflow++;
            break;
        case 7:
            reg->ptr_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr1intfifoMetrics::Publish(key, reg);
        break;
    }
    case 389:
    {
        delphi::objects::dprdpr1intflopfifo0metrics_t *reg = &dprdpr1intflopfifo0metrics;
        switch (field_id) {
        case 2:
            reg->data_mux_force_bypass_crc_flop_ff_ovflow++;
            break;
        case 3:
            reg->dpr_crc_info_flop_ff_ovflow++;
            break;
        case 4:
            reg->dpr_crc_update_info_flop_ff_ovflow++;
            break;
        case 5:
            reg->dpr_csum_info_flop_ff_ovflow++;
            break;
        case 6:
            reg->data_mux_force_bypass_csum_flop_ff_ovflow++;
            break;
        case 7:
            reg->dpr_csum_update_info_flop_ff_ovflow++;
            break;
        case 8:
            reg->ptr_early_pkt_eop_info_flop_ff_ovflow++;
            break;
        case 9:
            reg->data_mux_eop_err_flop_ff_ovflow++;
            break;
        case 10:
            reg->pktin_eop_err_flop_ff_ovflow++;
            break;
        case 11:
            reg->csum_err_flop_ff_ovflow++;
            break;
        case 12:
            reg->crc_err_flop_ff_ovflow++;
            break;
        case 13:
            reg->data_mux_drop_flop_ff_ovflow++;
            break;
        case 14:
            reg->phv_pkt_data_flop_ff_ovflow++;
            break;
        case 15:
            reg->pktout_len_cell_flop_ff_ovflow++;
            break;
        case 16:
            reg->padding_size_flop_ff_ovflow++;
            break;
        case 17:
            reg->pktin_err_flop_ff_ovflow++;
            break;
        case 18:
            reg->phv_no_data_flop_ff_ovflow++;
            break;
        case 19:
            reg->ptr_lookahaed_flop_ff_ovflow++;
            break;
        case 20:
            reg->eop_vld_flop_ff_ovflow++;
            break;
        case 21:
            reg->csum_cal_vld_flop_ff_ovflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr1intflopfifo0Metrics::Publish(key, reg);
        break;
    }
    case 390:
    {
        delphi::objects::dprdpr1intflopfifo1metrics_t *reg = &dprdpr1intflopfifo1metrics;
        switch (field_id) {
        case 2:
            reg->data_mux_force_bypass_crc_flop_ff_undflow++;
            break;
        case 3:
            reg->dpr_crc_info_flop_ff_undflow++;
            break;
        case 4:
            reg->dpr_crc_update_info_flop_ff_undflow++;
            break;
        case 5:
            reg->dpr_csum_info_flop_ff_undflow++;
            break;
        case 6:
            reg->data_mux_force_bypass_csum_flop_ff_undflow++;
            break;
        case 7:
            reg->dpr_csum_update_info_flop_ff_undflow++;
            break;
        case 8:
            reg->ptr_early_pkt_eop_info_flop_ff_undflow++;
            break;
        case 9:
            reg->data_mux_eop_err_flop_ff_undflow++;
            break;
        case 10:
            reg->pktin_eop_err_flop_ff_undflow++;
            break;
        case 11:
            reg->csum_err_flop_ff_undflow++;
            break;
        case 12:
            reg->crc_err_flop_ff_undflow++;
            break;
        case 13:
            reg->data_mux_drop_flop_ff_undflow++;
            break;
        case 14:
            reg->phv_pkt_data_flop_ff_undflow++;
            break;
        case 15:
            reg->pktout_len_cell_flop_ff_undflow++;
            break;
        case 16:
            reg->padding_size_flop_ff_undflow++;
            break;
        case 17:
            reg->pktin_err_flop_ff_undflow++;
            break;
        case 18:
            reg->phv_no_data_flop_ff_undflow++;
            break;
        case 19:
            reg->ptr_lookahaed_flop_ff_undflow++;
            break;
        case 20:
            reg->eop_vld_flop_ff_undflow++;
            break;
        case 21:
            reg->csum_cal_vld_flop_ff_undflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr1intflopfifo1Metrics::Publish(key, reg);
        break;
    }
    case 391:
    {
        delphi::objects::dprdpr1intsparemetrics_t *reg = &dprdpr1intsparemetrics;
        switch (field_id) {
        case 2:
            reg->spare_0++;
            break;
        case 3:
            reg->spare_1++;
            break;
        case 4:
            reg->spare_2++;
            break;
        case 5:
            reg->spare_3++;
            break;
        case 6:
            reg->spare_4++;
            break;
        case 7:
            reg->spare_5++;
            break;
        case 8:
            reg->spare_6++;
            break;
        case 9:
            reg->spare_7++;
            break;
        case 10:
            reg->spare_8++;
            break;
        case 11:
            reg->spare_9++;
            break;
        case 12:
            reg->spare_10++;
            break;
        case 13:
            reg->spare_11++;
            break;
        case 14:
            reg->spare_12++;
            break;
        case 15:
            reg->spare_13++;
            break;
        case 16:
            reg->spare_14++;
            break;
        case 17:
            reg->spare_15++;
            break;
        case 18:
            reg->spare_16++;
            break;
        case 19:
            reg->spare_17++;
            break;
        case 20:
            reg->spare_18++;
            break;
        case 21:
            reg->spare_19++;
            break;
        case 22:
            reg->spare_20++;
            break;
        case 23:
            reg->spare_21++;
            break;
        case 24:
            reg->spare_22++;
            break;
        case 25:
            reg->spare_23++;
            break;
        case 26:
            reg->spare_24++;
            break;
        case 27:
            reg->spare_25++;
            break;
        case 28:
            reg->spare_26++;
            break;
        case 29:
            reg->spare_27++;
            break;
        case 30:
            reg->spare_28++;
            break;
        case 31:
            reg->spare_29++;
            break;
        case 32:
            reg->spare_30++;
            break;
        case 33:
            reg->spare_31++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr1intspareMetrics::Publish(key, reg);
        break;
    }
    case 392:
    {
        delphi::objects::dprdpr1intcreditmetrics_t *reg = &dprdpr1intcreditmetrics;
        switch (field_id) {
        case 2:
            reg->egress_credit_ovflow++;
            break;
        case 3:
            reg->egress_credit_undflow++;
            break;
        case 4:
            reg->pktout_credit_ovflow++;
            break;
        case 5:
            reg->pktout_credit_undflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dprdpr1intcreditMetrics::Publish(key, reg);
        break;
    }
    case 394:
    {
        delphi::objects::mcmc0intmcmetrics_t *reg = &mcmc0intmcmetrics;
        switch (field_id) {
        case 2:
            reg->mch_int++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc0intmcMetrics::Publish(key, reg);
        break;
    }
    case 396:
    {
        delphi::objects::mcmc0mchintmcmetrics_t *reg = &mcmc0mchintmcmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_1bit_thresh_ps1++;
            break;
        case 3:
            reg->ecc_1bit_thresh_ps0++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc0mchintmcMetrics::Publish(key, reg);
        break;
    }
    case 398:
    {
        delphi::objects::mcmc1intmcmetrics_t *reg = &mcmc1intmcmetrics;
        switch (field_id) {
        case 2:
            reg->mch_int++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc1intmcMetrics::Publish(key, reg);
        break;
    }
    case 400:
    {
        delphi::objects::mcmc1mchintmcmetrics_t *reg = &mcmc1mchintmcmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_1bit_thresh_ps1++;
            break;
        case 3:
            reg->ecc_1bit_thresh_ps0++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc1mchintmcMetrics::Publish(key, reg);
        break;
    }
    case 402:
    {
        delphi::objects::mcmc2intmcmetrics_t *reg = &mcmc2intmcmetrics;
        switch (field_id) {
        case 2:
            reg->mch_int++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc2intmcMetrics::Publish(key, reg);
        break;
    }
    case 404:
    {
        delphi::objects::mcmc2mchintmcmetrics_t *reg = &mcmc2mchintmcmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_1bit_thresh_ps1++;
            break;
        case 3:
            reg->ecc_1bit_thresh_ps0++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc2mchintmcMetrics::Publish(key, reg);
        break;
    }
    case 406:
    {
        delphi::objects::mcmc3intmcmetrics_t *reg = &mcmc3intmcmetrics;
        switch (field_id) {
        case 2:
            reg->mch_int++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc3intmcMetrics::Publish(key, reg);
        break;
    }
    case 408:
    {
        delphi::objects::mcmc3mchintmcmetrics_t *reg = &mcmc3mchintmcmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_1bit_thresh_ps1++;
            break;
        case 3:
            reg->ecc_1bit_thresh_ps0++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc3mchintmcMetrics::Publish(key, reg);
        break;
    }
    case 410:
    {
        delphi::objects::mcmc4intmcmetrics_t *reg = &mcmc4intmcmetrics;
        switch (field_id) {
        case 2:
            reg->mch_int++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc4intmcMetrics::Publish(key, reg);
        break;
    }
    case 412:
    {
        delphi::objects::mcmc4mchintmcmetrics_t *reg = &mcmc4mchintmcmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_1bit_thresh_ps1++;
            break;
        case 3:
            reg->ecc_1bit_thresh_ps0++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc4mchintmcMetrics::Publish(key, reg);
        break;
    }
    case 414:
    {
        delphi::objects::mcmc5intmcmetrics_t *reg = &mcmc5intmcmetrics;
        switch (field_id) {
        case 2:
            reg->mch_int++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc5intmcMetrics::Publish(key, reg);
        break;
    }
    case 416:
    {
        delphi::objects::mcmc5mchintmcmetrics_t *reg = &mcmc5mchintmcmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_1bit_thresh_ps1++;
            break;
        case 3:
            reg->ecc_1bit_thresh_ps0++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc5mchintmcMetrics::Publish(key, reg);
        break;
    }
    case 418:
    {
        delphi::objects::mcmc6intmcmetrics_t *reg = &mcmc6intmcmetrics;
        switch (field_id) {
        case 2:
            reg->mch_int++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc6intmcMetrics::Publish(key, reg);
        break;
    }
    case 420:
    {
        delphi::objects::mcmc6mchintmcmetrics_t *reg = &mcmc6mchintmcmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_1bit_thresh_ps1++;
            break;
        case 3:
            reg->ecc_1bit_thresh_ps0++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc6mchintmcMetrics::Publish(key, reg);
        break;
    }
    case 422:
    {
        delphi::objects::mcmc7intmcmetrics_t *reg = &mcmc7intmcmetrics;
        switch (field_id) {
        case 2:
            reg->mch_int++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc7intmcMetrics::Publish(key, reg);
        break;
    }
    case 424:
    {
        delphi::objects::mcmc7mchintmcmetrics_t *reg = &mcmc7mchintmcmetrics;
        switch (field_id) {
        case 2:
            reg->ecc_1bit_thresh_ps1++;
            break;
        case 3:
            reg->ecc_1bit_thresh_ps0++;
            break;
        default:
            break;
        }
        delphi::objects::Mcmc7mchintmcMetrics::Publish(key, reg);
        break;
    }
    case 426:
    {
        delphi::objects::dppdpp0intreg1metrics_t *reg = &dppdpp0intreg1metrics;
        switch (field_id) {
        case 2:
            reg->err_phv_sop_no_eop++;
            break;
        case 3:
            reg->err_phv_eop_no_sop++;
            break;
        case 4:
            reg->err_ohi_sop_no_eop++;
            break;
        case 5:
            reg->err_ohi_eop_no_sop++;
            break;
        case 6:
            reg->err_framer_credit_overrun++;
            break;
        case 7:
            reg->err_packets_in_flight_credit_overrun++;
            break;
        case 8:
            reg->err_null_hdr_vld++;
            break;
        case 9:
            reg->err_null_hdrfld_vld++;
            break;
        case 10:
            reg->err_max_pkt_size++;
            break;
        case 11:
            reg->err_max_active_hdrs++;
            break;
        case 12:
            reg->err_phv_no_data_reference_ohi++;
            break;
        case 13:
            reg->err_csum_multiple_hdr++;
            break;
        case 14:
            reg->err_csum_multiple_hdr_copy++;
            break;
        case 15:
            reg->err_crc_multiple_hdr++;
            break;
        case 16:
            reg->err_ptr_fifo_credit_overrun++;
            break;
        case 17:
            reg->err_clip_max_pkt_size++;
            break;
        case 18:
            reg->err_min_pkt_size++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp0intreg1Metrics::Publish(key, reg);
        break;
    }
    case 427:
    {
        delphi::objects::dppdpp0intreg2metrics_t *reg = &dppdpp0intreg2metrics;
        switch (field_id) {
        case 2:
            reg->fieldC++;
            break;
        case 3:
            reg->fieldD++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp0intreg2Metrics::Publish(key, reg);
        break;
    }
    case 428:
    {
        delphi::objects::dppdpp0intsramseccmetrics_t *reg = &dppdpp0intsramseccmetrics;
        switch (field_id) {
        case 2:
            reg->dpp_phv_fifo_uncorrectable++;
            break;
        case 3:
            reg->dpp_phv_fifo_correctable++;
            break;
        case 4:
            reg->dpp_ohi_fifo_uncorrectable++;
            break;
        case 5:
            reg->dpp_ohi_fifo_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp0intsramseccMetrics::Publish(key, reg);
        break;
    }
    case 429:
    {
        delphi::objects::dppdpp0intfifometrics_t *reg = &dppdpp0intfifometrics;
        switch (field_id) {
        case 2:
            reg->phv_ff_overflow++;
            break;
        case 3:
            reg->ohi_ff_overflow++;
            break;
        case 4:
            reg->pkt_size_ff_ovflow++;
            break;
        case 5:
            reg->pkt_size_ff_undflow++;
            break;
        case 6:
            reg->csum_phv_ff_ovflow++;
            break;
        case 7:
            reg->csum_phv_ff_undflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp0intfifoMetrics::Publish(key, reg);
        break;
    }
    case 430:
    {
        delphi::objects::dppdpp0intsparemetrics_t *reg = &dppdpp0intsparemetrics;
        switch (field_id) {
        case 2:
            reg->spare_0++;
            break;
        case 3:
            reg->spare_1++;
            break;
        case 4:
            reg->spare_2++;
            break;
        case 5:
            reg->spare_3++;
            break;
        case 6:
            reg->spare_4++;
            break;
        case 7:
            reg->spare_5++;
            break;
        case 8:
            reg->spare_6++;
            break;
        case 9:
            reg->spare_7++;
            break;
        case 10:
            reg->spare_8++;
            break;
        case 11:
            reg->spare_9++;
            break;
        case 12:
            reg->spare_10++;
            break;
        case 13:
            reg->spare_11++;
            break;
        case 14:
            reg->spare_12++;
            break;
        case 15:
            reg->spare_13++;
            break;
        case 16:
            reg->spare_14++;
            break;
        case 17:
            reg->spare_15++;
            break;
        case 18:
            reg->spare_16++;
            break;
        case 19:
            reg->spare_17++;
            break;
        case 20:
            reg->spare_18++;
            break;
        case 21:
            reg->spare_19++;
            break;
        case 22:
            reg->spare_20++;
            break;
        case 23:
            reg->spare_21++;
            break;
        case 24:
            reg->spare_22++;
            break;
        case 25:
            reg->spare_23++;
            break;
        case 26:
            reg->spare_24++;
            break;
        case 27:
            reg->spare_25++;
            break;
        case 28:
            reg->spare_26++;
            break;
        case 29:
            reg->spare_27++;
            break;
        case 30:
            reg->spare_28++;
            break;
        case 31:
            reg->spare_29++;
            break;
        case 32:
            reg->spare_30++;
            break;
        case 33:
            reg->spare_31++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp0intspareMetrics::Publish(key, reg);
        break;
    }
    case 431:
    {
        delphi::objects::dppdpp0intcreditmetrics_t *reg = &dppdpp0intcreditmetrics;
        switch (field_id) {
        case 2:
            reg->ptr_credit_ovflow++;
            break;
        case 3:
            reg->ptr_credit_undflow++;
            break;
        case 4:
            reg->pkt_credit_ovflow++;
            break;
        case 5:
            reg->pkt_credit_undflow++;
            break;
        case 6:
            reg->framer_credit_ovflow++;
            break;
        case 7:
            reg->framer_credit_undflow++;
            break;
        case 8:
            reg->framer_hdrfld_vld_ovfl++;
            break;
        case 9:
            reg->framer_hdrfld_offset_ovfl++;
            break;
        case 10:
            reg->err_framer_hdrsize_zero_ovfl++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp0intcreditMetrics::Publish(key, reg);
        break;
    }
    case 433:
    {
        delphi::objects::dppdpp1intreg1metrics_t *reg = &dppdpp1intreg1metrics;
        switch (field_id) {
        case 2:
            reg->err_phv_sop_no_eop++;
            break;
        case 3:
            reg->err_phv_eop_no_sop++;
            break;
        case 4:
            reg->err_ohi_sop_no_eop++;
            break;
        case 5:
            reg->err_ohi_eop_no_sop++;
            break;
        case 6:
            reg->err_framer_credit_overrun++;
            break;
        case 7:
            reg->err_packets_in_flight_credit_overrun++;
            break;
        case 8:
            reg->err_null_hdr_vld++;
            break;
        case 9:
            reg->err_null_hdrfld_vld++;
            break;
        case 10:
            reg->err_max_pkt_size++;
            break;
        case 11:
            reg->err_max_active_hdrs++;
            break;
        case 12:
            reg->err_phv_no_data_reference_ohi++;
            break;
        case 13:
            reg->err_csum_multiple_hdr++;
            break;
        case 14:
            reg->err_csum_multiple_hdr_copy++;
            break;
        case 15:
            reg->err_crc_multiple_hdr++;
            break;
        case 16:
            reg->err_ptr_fifo_credit_overrun++;
            break;
        case 17:
            reg->err_clip_max_pkt_size++;
            break;
        case 18:
            reg->err_min_pkt_size++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp1intreg1Metrics::Publish(key, reg);
        break;
    }
    case 434:
    {
        delphi::objects::dppdpp1intreg2metrics_t *reg = &dppdpp1intreg2metrics;
        switch (field_id) {
        case 2:
            reg->fieldC++;
            break;
        case 3:
            reg->fieldD++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp1intreg2Metrics::Publish(key, reg);
        break;
    }
    case 435:
    {
        delphi::objects::dppdpp1intsramseccmetrics_t *reg = &dppdpp1intsramseccmetrics;
        switch (field_id) {
        case 2:
            reg->dpp_phv_fifo_uncorrectable++;
            break;
        case 3:
            reg->dpp_phv_fifo_correctable++;
            break;
        case 4:
            reg->dpp_ohi_fifo_uncorrectable++;
            break;
        case 5:
            reg->dpp_ohi_fifo_correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp1intsramseccMetrics::Publish(key, reg);
        break;
    }
    case 436:
    {
        delphi::objects::dppdpp1intfifometrics_t *reg = &dppdpp1intfifometrics;
        switch (field_id) {
        case 2:
            reg->phv_ff_overflow++;
            break;
        case 3:
            reg->ohi_ff_overflow++;
            break;
        case 4:
            reg->pkt_size_ff_ovflow++;
            break;
        case 5:
            reg->pkt_size_ff_undflow++;
            break;
        case 6:
            reg->csum_phv_ff_ovflow++;
            break;
        case 7:
            reg->csum_phv_ff_undflow++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp1intfifoMetrics::Publish(key, reg);
        break;
    }
    case 437:
    {
        delphi::objects::dppdpp1intsparemetrics_t *reg = &dppdpp1intsparemetrics;
        switch (field_id) {
        case 2:
            reg->spare_0++;
            break;
        case 3:
            reg->spare_1++;
            break;
        case 4:
            reg->spare_2++;
            break;
        case 5:
            reg->spare_3++;
            break;
        case 6:
            reg->spare_4++;
            break;
        case 7:
            reg->spare_5++;
            break;
        case 8:
            reg->spare_6++;
            break;
        case 9:
            reg->spare_7++;
            break;
        case 10:
            reg->spare_8++;
            break;
        case 11:
            reg->spare_9++;
            break;
        case 12:
            reg->spare_10++;
            break;
        case 13:
            reg->spare_11++;
            break;
        case 14:
            reg->spare_12++;
            break;
        case 15:
            reg->spare_13++;
            break;
        case 16:
            reg->spare_14++;
            break;
        case 17:
            reg->spare_15++;
            break;
        case 18:
            reg->spare_16++;
            break;
        case 19:
            reg->spare_17++;
            break;
        case 20:
            reg->spare_18++;
            break;
        case 21:
            reg->spare_19++;
            break;
        case 22:
            reg->spare_20++;
            break;
        case 23:
            reg->spare_21++;
            break;
        case 24:
            reg->spare_22++;
            break;
        case 25:
            reg->spare_23++;
            break;
        case 26:
            reg->spare_24++;
            break;
        case 27:
            reg->spare_25++;
            break;
        case 28:
            reg->spare_26++;
            break;
        case 29:
            reg->spare_27++;
            break;
        case 30:
            reg->spare_28++;
            break;
        case 31:
            reg->spare_29++;
            break;
        case 32:
            reg->spare_30++;
            break;
        case 33:
            reg->spare_31++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp1intspareMetrics::Publish(key, reg);
        break;
    }
    case 438:
    {
        delphi::objects::dppdpp1intcreditmetrics_t *reg = &dppdpp1intcreditmetrics;
        switch (field_id) {
        case 2:
            reg->ptr_credit_ovflow++;
            break;
        case 3:
            reg->ptr_credit_undflow++;
            break;
        case 4:
            reg->pkt_credit_ovflow++;
            break;
        case 5:
            reg->pkt_credit_undflow++;
            break;
        case 6:
            reg->framer_credit_ovflow++;
            break;
        case 7:
            reg->framer_credit_undflow++;
            break;
        case 8:
            reg->framer_hdrfld_vld_ovfl++;
            break;
        case 9:
            reg->framer_hdrfld_offset_ovfl++;
            break;
        case 10:
            reg->err_framer_hdrsize_zero_ovfl++;
            break;
        default:
            break;
        }
        delphi::objects::Dppdpp1intcreditMetrics::Publish(key, reg);
        break;
    }
    case 440:
    {
        delphi::objects::semasemaintgroupsintregmetrics_t *reg = &semasemaintgroupsintregmetrics;
        switch (field_id) {
        case 2:
            reg->sema_err++;
            break;
        default:
            break;
        }
        delphi::objects::SemasemaintgroupsintregMetrics::Publish(key, reg);
        break;
    }
    case 441:
    {
        delphi::objects::mpmpnsintcryptometrics_t *reg = &mpmpnsintcryptometrics;
        switch (field_id) {
        case 2:
            reg->mpp0++;
            break;
        case 3:
            reg->mpp1++;
            break;
        case 4:
            reg->mpp2++;
            break;
        case 5:
            reg->mpp3++;
            break;
        case 6:
            reg->mpp4++;
            break;
        case 7:
            reg->mpp5++;
            break;
        case 8:
            reg->mpp6++;
            break;
        case 9:
            reg->mpp7++;
            break;
        default:
            break;
        }
        delphi::objects::MpmpnsintcryptoMetrics::Publish(key, reg);
        break;
    }
    case 443:
    {
        delphi::objects::msmsintmsmetrics_t *reg = &msmsintmsmetrics;
        switch (field_id) {
        case 2:
            reg->sbus_err++;
            break;
        case 3:
            reg->rei_err++;
            break;
        case 4:
            reg->rei_pll_err++;
            break;
        case 5:
            reg->pk_efuse_init_read_timeout++;
            break;
        case 6:
            reg->pk_efuse_cpu_read_timeout++;
            break;
        case 7:
            reg->pk_efuse_cpu_burn_timeout++;
            break;
        case 8:
            reg->pk_efuse_burn_imm_timeout++;
            break;
        case 9:
            reg->ds16_efuse_init_read_timeout++;
            break;
        case 10:
            reg->ds16_efuse_cpu_read_timeout++;
            break;
        case 11:
            reg->ahb_axi_err++;
            break;
        case 12:
            reg->emmc_pre_axi_err++;
            break;
        case 13:
            reg->fl_axi_err++;
            break;
        case 14:
            reg->ms_esec_mb_pre_axi_err++;
            break;
        case 15:
            reg->msap_pre_axi_err++;
            break;
        case 16:
            reg->nxms_a13_axi_err++;
            break;
        case 17:
            reg->rbm_axi_err++;
            break;
        case 18:
            reg->ssram_axi_err++;
            break;
        case 19:
            reg->ahb_axi_werr++;
            break;
        case 20:
            reg->emmc_pre_axi_werr++;
            break;
        case 21:
            reg->fl_axi_werr++;
            break;
        case 22:
            reg->ms_esec_mb_pre_axi_werr++;
            break;
        case 23:
            reg->msap_pre_axi_werr++;
            break;
        case 24:
            reg->nxms_a13_axi_werr++;
            break;
        case 25:
            reg->rbm_axi_werr++;
            break;
        case 26:
            reg->ssram_axi_werr++;
            break;
        case 27:
            reg->addr_filter_write++;
            break;
        case 28:
            reg->addr_filter_read++;
            break;
        default:
            break;
        }
        delphi::objects::MsmsintmsMetrics::Publish(key, reg);
        break;
    }
    case 444:
    {
        delphi::objects::msmsintmiscmetrics_t *reg = &msmsintmiscmetrics;
        switch (field_id) {
        case 2:
            reg->qspi_ram_ecc_uncorrectable++;
            break;
        case 3:
            reg->qspi_ram_ecc_correctable++;
            break;
        case 4:
            reg->elam_cap_ecc_uncorrectable++;
            break;
        case 5:
            reg->elam_cap_ecc_correctable++;
            break;
        case 6:
            reg->ahb_esec_data_ram_ecc_uncorrectable++;
            break;
        case 7:
            reg->ahb_esec_data_ram_ecc_correctable++;
            break;
        case 8:
            reg->ahb_esec_esystem_ram_ecc_uncorrectable++;
            break;
        case 9:
            reg->ahb_esec_esystem_ram_ecc_correctable++;
            break;
        case 10:
            reg->bl2_ram_ecc_uncorrectable++;
            break;
        case 11:
            reg->bl2_ram_ecc_correctable++;
            break;
        case 12:
            reg->int_wr_stall_hit0_interrupt++;
            break;
        case 13:
            reg->int_rd_stall_hit0_interrupt++;
            break;
        case 14:
            reg->int_wr_stall_hit1_interrupt++;
            break;
        case 15:
            reg->int_rd_stall_hit1_interrupt++;
            break;
        case 16:
            reg->int_wr_stall_hit2_interrupt++;
            break;
        case 17:
            reg->int_rd_stall_hit2_interrupt++;
            break;
        case 18:
            reg->int_wr_full0_interrupt++;
            break;
        case 19:
            reg->int_rd_full0_interrupt++;
            break;
        case 20:
            reg->int_wr_full1_interrupt++;
            break;
        case 21:
            reg->int_rd_full1_interrupt++;
            break;
        case 22:
            reg->int_wr_full2_interrupt++;
            break;
        case 23:
            reg->int_rd_full2_interrupt++;
            break;
        default:
            break;
        }
        delphi::objects::MsmsintmiscMetrics::Publish(key, reg);
        break;
    }
    case 445:
    {
        delphi::objects::msmsintesecuremetrics_t *reg = &msmsintesecuremetrics;
        switch (field_id) {
        case 2:
            reg->mb_rxint++;
            break;
        case 3:
            reg->mb_txint++;
            break;
        default:
            break;
        }
        delphi::objects::MsmsintesecureMetrics::Publish(key, reg);
        break;
    }
    case 446:
    {
        delphi::objects::msmsintprp1metrics_t *reg = &msmsintprp1metrics;
        switch (field_id) {
        case 2:
            reg->read++;
            break;
        case 3:
            reg->security++;
            break;
        case 4:
            reg->decode++;
            break;
        case 5:
            reg->ack_timeout++;
            break;
        case 6:
            reg->stall_timeout++;
            break;
        case 7:
            reg->byte_read++;
            break;
        case 8:
            reg->byte_write++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintprp1Metrics::Publish(key, reg);
        break;
    }
    case 447:
    {
        delphi::objects::msmsintprp2metrics_t *reg = &msmsintprp2metrics;
        switch (field_id) {
        case 2:
            reg->read++;
            break;
        case 3:
            reg->security++;
            break;
        case 4:
            reg->decode++;
            break;
        case 5:
            reg->ack_timeout++;
            break;
        case 6:
            reg->stall_timeout++;
            break;
        case 7:
            reg->byte_read++;
            break;
        case 8:
            reg->byte_write++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintprp2Metrics::Publish(key, reg);
        break;
    }
    case 448:
    {
        delphi::objects::msmsintprp3metrics_t *reg = &msmsintprp3metrics;
        switch (field_id) {
        case 2:
            reg->read++;
            break;
        case 3:
            reg->security++;
            break;
        case 4:
            reg->decode++;
            break;
        case 5:
            reg->ack_timeout++;
            break;
        case 6:
            reg->stall_timeout++;
            break;
        case 7:
            reg->byte_read++;
            break;
        case 8:
            reg->byte_write++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintprp3Metrics::Publish(key, reg);
        break;
    }
    case 449:
    {
        delphi::objects::msmsintprp4metrics_t *reg = &msmsintprp4metrics;
        switch (field_id) {
        case 2:
            reg->read++;
            break;
        case 3:
            reg->security++;
            break;
        case 4:
            reg->decode++;
            break;
        case 5:
            reg->ack_timeout++;
            break;
        case 6:
            reg->stall_timeout++;
            break;
        case 7:
            reg->byte_read++;
            break;
        case 8:
            reg->byte_write++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintprp4Metrics::Publish(key, reg);
        break;
    }
    case 450:
    {
        delphi::objects::msmsintprp5metrics_t *reg = &msmsintprp5metrics;
        switch (field_id) {
        case 2:
            reg->read++;
            break;
        case 3:
            reg->security++;
            break;
        case 4:
            reg->decode++;
            break;
        case 5:
            reg->ack_timeout++;
            break;
        case 6:
            reg->stall_timeout++;
            break;
        case 7:
            reg->byte_read++;
            break;
        case 8:
            reg->byte_write++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintprp5Metrics::Publish(key, reg);
        break;
    }
    case 451:
    {
        delphi::objects::msmsintgic0metrics_t *reg = &msmsintgic0metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic0Metrics::Publish(key, reg);
        break;
    }
    case 452:
    {
        delphi::objects::msmsintgic1metrics_t *reg = &msmsintgic1metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic1Metrics::Publish(key, reg);
        break;
    }
    case 453:
    {
        delphi::objects::msmsintgic2metrics_t *reg = &msmsintgic2metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic2Metrics::Publish(key, reg);
        break;
    }
    case 454:
    {
        delphi::objects::msmsintgic3metrics_t *reg = &msmsintgic3metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic3Metrics::Publish(key, reg);
        break;
    }
    case 455:
    {
        delphi::objects::msmsintgic4metrics_t *reg = &msmsintgic4metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic4Metrics::Publish(key, reg);
        break;
    }
    case 456:
    {
        delphi::objects::msmsintgic5metrics_t *reg = &msmsintgic5metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic5Metrics::Publish(key, reg);
        break;
    }
    case 457:
    {
        delphi::objects::msmsintgic6metrics_t *reg = &msmsintgic6metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic6Metrics::Publish(key, reg);
        break;
    }
    case 458:
    {
        delphi::objects::msmsintgic7metrics_t *reg = &msmsintgic7metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic7Metrics::Publish(key, reg);
        break;
    }
    case 459:
    {
        delphi::objects::msmsintgic8metrics_t *reg = &msmsintgic8metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic8Metrics::Publish(key, reg);
        break;
    }
    case 460:
    {
        delphi::objects::msmsintgic9metrics_t *reg = &msmsintgic9metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic9Metrics::Publish(key, reg);
        break;
    }
    case 461:
    {
        delphi::objects::msmsintgic10metrics_t *reg = &msmsintgic10metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic10Metrics::Publish(key, reg);
        break;
    }
    case 462:
    {
        delphi::objects::msmsintgic11metrics_t *reg = &msmsintgic11metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic11Metrics::Publish(key, reg);
        break;
    }
    case 463:
    {
        delphi::objects::msmsintgic12metrics_t *reg = &msmsintgic12metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic12Metrics::Publish(key, reg);
        break;
    }
    case 464:
    {
        delphi::objects::msmsintgic13metrics_t *reg = &msmsintgic13metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic13Metrics::Publish(key, reg);
        break;
    }
    case 465:
    {
        delphi::objects::msmsintgic14metrics_t *reg = &msmsintgic14metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic14Metrics::Publish(key, reg);
        break;
    }
    case 466:
    {
        delphi::objects::msmsintgic15metrics_t *reg = &msmsintgic15metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic15Metrics::Publish(key, reg);
        break;
    }
    case 467:
    {
        delphi::objects::msmsintgic16metrics_t *reg = &msmsintgic16metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic16Metrics::Publish(key, reg);
        break;
    }
    case 468:
    {
        delphi::objects::msmsintgic17metrics_t *reg = &msmsintgic17metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic17Metrics::Publish(key, reg);
        break;
    }
    case 469:
    {
        delphi::objects::msmsintgic18metrics_t *reg = &msmsintgic18metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic18Metrics::Publish(key, reg);
        break;
    }
    case 470:
    {
        delphi::objects::msmsintgic19metrics_t *reg = &msmsintgic19metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic19Metrics::Publish(key, reg);
        break;
    }
    case 471:
    {
        delphi::objects::msmsintgic20metrics_t *reg = &msmsintgic20metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic20Metrics::Publish(key, reg);
        break;
    }
    case 472:
    {
        delphi::objects::msmsintgic21metrics_t *reg = &msmsintgic21metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic21Metrics::Publish(key, reg);
        break;
    }
    case 473:
    {
        delphi::objects::msmsintgic22metrics_t *reg = &msmsintgic22metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic22Metrics::Publish(key, reg);
        break;
    }
    case 474:
    {
        delphi::objects::msmsintgic23metrics_t *reg = &msmsintgic23metrics;
        switch (field_id) {
        case 2:
            reg->msar_int_lvl++;
            break;
        default:
            break;
        }
        delphi::objects::Msmsintgic23Metrics::Publish(key, reg);
        break;
    }
    case 476:
    {
        delphi::objects::msemintgroupsintregmetrics_t *reg = &msemintgroupsintregmetrics;
        switch (field_id) {
        case 2:
            reg->axi++;
            break;
        default:
            break;
        }
        delphi::objects::MsemintgroupsintregMetrics::Publish(key, reg);
        break;
    }
    case 477:
    {
        delphi::objects::mxmx0intmacmetrics_t *reg = &mxmx0intmacmetrics;
        switch (field_id) {
        case 2:
            reg->lane0_sbe++;
            break;
        case 3:
            reg->lane0_dbe++;
            break;
        case 4:
            reg->lane1_sbe++;
            break;
        case 5:
            reg->lane1_dbe++;
            break;
        case 6:
            reg->lane2_sbe++;
            break;
        case 7:
            reg->lane2_dbe++;
            break;
        case 8:
            reg->lane3_sbe++;
            break;
        case 9:
            reg->lane3_dbe++;
            break;
        case 10:
            reg->umac_CFG3_intr++;
            break;
        case 11:
            reg->umac_CFG3_pslverr++;
            break;
        case 12:
            reg->m0pb_pbus_drdy++;
            break;
        case 13:
            reg->m1pb_pbus_drdy++;
            break;
        case 14:
            reg->m2pb_pbus_drdy++;
            break;
        case 15:
            reg->m3pb_pbus_drdy++;
            break;
        case 16:
            reg->rx0_missing_sof++;
            break;
        case 17:
            reg->rx0_missing_eof++;
            break;
        case 18:
            reg->rx0_timeout_err++;
            break;
        case 19:
            reg->rx0_min_size_err++;
            break;
        case 20:
            reg->rx1_missing_sof++;
            break;
        case 21:
            reg->rx1_missing_eof++;
            break;
        case 22:
            reg->rx1_timeout_err++;
            break;
        case 23:
            reg->rx1_min_size_err++;
            break;
        case 24:
            reg->rx2_missing_sof++;
            break;
        case 25:
            reg->rx2_missing_eof++;
            break;
        case 26:
            reg->rx2_timeout_err++;
            break;
        case 27:
            reg->rx2_min_size_err++;
            break;
        case 28:
            reg->rx3_missing_sof++;
            break;
        case 29:
            reg->rx3_missing_eof++;
            break;
        case 30:
            reg->rx3_timeout_err++;
            break;
        case 31:
            reg->rx3_min_size_err++;
            break;
        default:
            break;
        }
        delphi::objects::Mxmx0intmacMetrics::Publish(key, reg);
        break;
    }
    case 478:
    {
        delphi::objects::mxmx0inteccmetrics_t *reg = &mxmx0inteccmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Mxmx0inteccMetrics::Publish(key, reg);
        break;
    }
    case 480:
    {
        delphi::objects::mxmx1intmacmetrics_t *reg = &mxmx1intmacmetrics;
        switch (field_id) {
        case 2:
            reg->lane0_sbe++;
            break;
        case 3:
            reg->lane0_dbe++;
            break;
        case 4:
            reg->lane1_sbe++;
            break;
        case 5:
            reg->lane1_dbe++;
            break;
        case 6:
            reg->lane2_sbe++;
            break;
        case 7:
            reg->lane2_dbe++;
            break;
        case 8:
            reg->lane3_sbe++;
            break;
        case 9:
            reg->lane3_dbe++;
            break;
        case 10:
            reg->umac_CFG3_intr++;
            break;
        case 11:
            reg->umac_CFG3_pslverr++;
            break;
        case 12:
            reg->m0pb_pbus_drdy++;
            break;
        case 13:
            reg->m1pb_pbus_drdy++;
            break;
        case 14:
            reg->m2pb_pbus_drdy++;
            break;
        case 15:
            reg->m3pb_pbus_drdy++;
            break;
        case 16:
            reg->rx0_missing_sof++;
            break;
        case 17:
            reg->rx0_missing_eof++;
            break;
        case 18:
            reg->rx0_timeout_err++;
            break;
        case 19:
            reg->rx0_min_size_err++;
            break;
        case 20:
            reg->rx1_missing_sof++;
            break;
        case 21:
            reg->rx1_missing_eof++;
            break;
        case 22:
            reg->rx1_timeout_err++;
            break;
        case 23:
            reg->rx1_min_size_err++;
            break;
        case 24:
            reg->rx2_missing_sof++;
            break;
        case 25:
            reg->rx2_missing_eof++;
            break;
        case 26:
            reg->rx2_timeout_err++;
            break;
        case 27:
            reg->rx2_min_size_err++;
            break;
        case 28:
            reg->rx3_missing_sof++;
            break;
        case 29:
            reg->rx3_missing_eof++;
            break;
        case 30:
            reg->rx3_timeout_err++;
            break;
        case 31:
            reg->rx3_min_size_err++;
            break;
        default:
            break;
        }
        delphi::objects::Mxmx1intmacMetrics::Publish(key, reg);
        break;
    }
    case 481:
    {
        delphi::objects::mxmx1inteccmetrics_t *reg = &mxmx1inteccmetrics;
        switch (field_id) {
        case 2:
            reg->uncorrectable++;
            break;
        case 3:
            reg->correctable++;
            break;
        default:
            break;
        }
        delphi::objects::Mxmx1inteccMetrics::Publish(key, reg);
        break;
    }
    default:
        break;
    }
    return SDK_RET_OK;
}