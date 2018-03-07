#ifndef __PD_API_C_H__
#define __PD_API_C_H__

#ifdef __cplusplus
extern "C" {
#endif

int pd_tls_asym_ecdsa_p256_sig_verify(uint8_t *p, uint8_t *n,
        uint8_t *xg, uint8_t *yg, uint8_t *a, uint8_t *b, uint8_t *xq,
        uint8_t *yq, uint8_t *r, uint8_t *s, uint8_t *h);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __PD_API_C_H__ */
