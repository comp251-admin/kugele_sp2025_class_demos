#pragma once

#define MAX 64

void startMachine(const char *id);
void revealSecrets();
void selfDestruct();

extern const char *cipher_block[MAX];
