#include <stdio.h>
#include <stdlib.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/err.h>

void print_sha256_fingerprint(X509 *cert) {
    unsigned char md[EVP_MAX_MD_SIZE];
    unsigned int n = 0;

    if (!X509_digest(cert, EVP_sha256(), md, &n)) {
        fprintf(stderr, "Error calculating SHA256 digest\n");
        return;
    }

    // Print as lowercase hex string without colons
    for (unsigned int i = 0; i < n; i++) {
        printf("%02x", md[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <certificate.pem>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *cert_path = argv[1];
    FILE *fp = fopen(cert_path, "r");
    if (!fp) {
        perror("Error opening certificate file");
        return EXIT_FAILURE;
    }

    OpenSSL_add_all_algorithms();
    ERR_load_BIO_strings();
    ERR_load_crypto_strings();

    X509 *cert = PEM_read_X509(fp, NULL, NULL, NULL);
    fclose(fp);

    if (!cert) {
        fprintf(stderr, "Error reading certificate from file\n");
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    print_sha256_fingerprint(cert);
    X509_free(cert);
    return EXIT_SUCCESS;
}
