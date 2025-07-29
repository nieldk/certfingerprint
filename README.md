# 🔐 X.509 SHA-256 Fingerprint Extractor

A lightweight C program that extracts the SHA-256 fingerprint of a PEM-encoded X.509 certificate and outputs it as a clean, lowercase hex string without colons — ideal for scripting, certificate pinning, or fingerprint comparisons.

---

## 📦 Features

- ✔️ Supports PEM-encoded X.509 certificates
- ✔️ Outputs clean SHA-256 fingerprint (lowercase, no colons)
- ✔️ Minimal dependencies (OpenSSL)
- ✔️ Fast and scriptable
- ✔️ Designed for Alpine Linux (but portable to most Unix systems)

---

## 📋 Example Output

```sh
./cert_fingerprint test.pem

6581d5d0cd82e86336a3a927d16d304be5e5064e2e2aa9a3bdd3d2e3daded4ad

