#include "secrets.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FAILURE_MSG_FMT "\033[5;41;33m%s\033[0m"
#define SUCCESS_MSG_FMT "\033[42;37m%s\033[0m"

void display(const char *fmt, const char *text, int delay_in_sec,
             bool newline) {
  printf(fmt, text);
  fflush(stdout);

  if (delay_in_sec) {
    sleep(delay_in_sec);
  }

  if (newline) {
    puts("");
  }
}

unsigned long getSeedFromName(const char *name) {
  unsigned long hash = 5381;
  int c;

  while ((c = *name++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}

void startMachine(const char *id) {
  int seed = getSeedFromName(id);
  srand(seed);
}

void revealSecrets() {
  int n_lucky = 7;

  display(SUCCESS_MSG_FMT, "Password Correct!", 1, true);
  display(SUCCESS_MSG_FMT, "Revealing secrets...", 3, true);

  printf("Your lucky numbers are...\n");
  for (int i = 0; i < n_lucky; i++) {
    printf("%d", (rand() % 100) + 1);
    if (i != n_lucky - 1) {
      printf(",");
    }
  }
  printf("\n");
}

void selfDestruct() {
  int n_countdown = 5;

  display(FAILURE_MSG_FMT, "Password Incorrect!", 1, true);
  display(FAILURE_MSG_FMT, "Initiating self-destruct sequence...", 3, true);

  for (int i = n_countdown; i > 0; i--) {
    printf("%d... ", i);
    fflush(stdout);
    sleep(1);
  }

  display(FAILURE_MSG_FMT, "BOOOOOOM!", 0, true);
}

/*
const char *cipher_block[MAX] = {
    "agent",      "cypher",      "stealth",   "shadow",     "covert",
    "infiltrate", "espionage",   "mission",   "spyglass",   "encrypted",
    "decrypt",    "cipher",      "sleeper",   "undercover", "classified",
    "intel",      "agentX",      "phantom",   "nighthawk",  "intruder",
    "bypass",     "hacktivate",  "keylogger", "firewall",   "backdoor",
    "malware",    "trojan",      "virus",     "worm",       "exploit",
    "rootkit",    "honeypot",    "sniffer",   "zeroday",    "blackhat",
    "whitehat",   "redteam",     "bluehat",   "packet",     "protocol",
    "botnet",     "cyber",       "spyware",   "bruteforce", "obfuscate",
    "decryptor",  "encryptor",   "dataheist", "sabotage",   "infiltrator",
    "decoy",      "smokescreen", "incognito", "alias",      "codenamed",
    "echelon",    "wiretap",     "snare",     "proxy",      "viper",
    "drone",      "sentry",      "signal",    "quantum"};
*/
const char *cipher_block[MAX] = {
    "ntrag",      "plcure",      "fgrnygu",    "funqbj",     "pbiereg",
    "vasvygengr", "rfcvbantr",   "zvffvba",    "fcltynff",   "rapelcgrq",
    "qrpelcg",    "pvcurve",     "fyrrcere",   "haqrepbire", "pynffvsvirq",
    "vagry",      "ntragK",      "cunagbz",    "avtugunjx",  "vagehqre",
    "olcnff",     "unpxgvingr",  "xrlybttrre", "sverjnyy",   "onpxqbbe",
    "znyjner",    "gebwna",      "ivehf",      "jbez",       "rkcybvg",
    "ebbgxvg",    "ubarlcbg",    "favssre",    "mrebqnl",    "oynpxung",
    "juvgrung",   "erqgernz",    "oyhrung",    "cnpxrg",     "cegbbpby",
    "obgarg",     "plore",       "fcljner",    "oehgrsbepr", "boshfpngr",
    "qrpelcgbe",  "rapelcgbe",   "qngnurvfg",  "fnobgntr",   "vasvygengbe",
    "qrpbl",      "fzbxrfperra", "vapbgtavgb", "nyvnf",      "pbqranzrq",
    "rpuryba",    "jvergnc",     "faner",      "cebkl",      "ivcre",
    "qebar",      "fragel",      "fvtany",     "dhnaghz"};
