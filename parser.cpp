#include <bits/stdc++.h>

using namespace std;

#define SIGMA_MAX_STATES 22
#define SIGMA_MAX_CHAR_CLASSES 23
#define ACTION_MAX_STATES 59
#define ACTION_MAX_TERMINALS 21
#define TRANSITION_MAX_STATES 59
#define TRANSITION_MAX_NON_TERMINALS 15

int sigma[SIGMA_MAX_STATES][SIGMA_MAX_CHAR_CLASSES] = {
////// 00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
////// \t, \n, SP, "", ((, )), **, ++, --, .., //, 09, ;;, <<, ==, >>, Az, EE, __, {{, }}, EF, OO,
/*00*/  0,  0,  0,  7, 19, 20, 18, 18, 18, -1, 18,  1, 21, 13, 15, 14,  9,  9, -2, 10, -3, 12, -4,
/*01*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  1,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,
/*02*/ -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  3, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
/*03*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,
/*04*/ -6, -6, -6, -6, -6, -6, -6,  5,  5, -6, -6,  6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,
/*05*/ -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  6, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,
/*06*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*07*/  7,  7,  7,  8,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, -8,  7,
/*08*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*09*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0,  9,  9,  9,  0,  0,  0,  0,
/*10*/ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, -9, 10,
/*11*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*12*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*13*/  0,  0,  0,  0,  0,  0,  0,  0, 17,  0,  0,  0,  0,  0, 15, 16,  0,  0,  0,  0,  0,  0,  0,
/*14*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15,  0,  0,  0,  0,  0,  0,  0,  0,
/*15*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*16*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*17*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*18*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*19*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*20*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*21*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

string action[ACTION_MAX_STATES][ACTION_MAX_TERMINALS] = {
    "S2",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",   "E0",     "",
    "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",   "E1",    "A",
    "E2",   "S4",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",   "E2",     "", 
    "E3",   "E3",   "E3",  "S12",   "E3",   "E3",   "E3",   "E3",  "S10",   "S11",   "E3",  "E3",   "E3",  "S14",   "E3",   "E3",   "S9",   "E3",   "E3",   "E3",     "",
   "E10",  "E10",  "S17",  "S18",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",     "",
   "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",  "R2!",   "R2",
    "E3",   "E3",   "E3",  "S12",   "E3",   "E3",   "E3",   "E3",  "S10",  "S11",   "E3",   "E3",   "E3",  "S14",   "E3",   "E3",   "S9",   "E3",   "E3",   "E3",     "",
    "E3",   "E3",   "E3",  "S12",   "E3",   "E3",   "E3",   "E3",  "S10",  "S11",   "E3",   "E3",   "E3",  "S14",   "E3",   "E3",   "S9",   "E3",   "E3",   "E3",     "",
    "E3",   "E3",   "E3",  "S12",   "E3",   "E3",   "E3",   "E3",  "S10",  "S11",   "E3",   "E3",   "E3",  "S14",   "E3",   "E3",   "S9",   "E3",   "E3",   "E3",     "",
  "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!", "R30!",  "R30",
    "E5",   "E5",   "E5",  "S22",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",   "E5",     "",
    "E6",   "E6",   "E6",  "S26",   "S25",  "E6",   "E6",  "S24",   "E6",   "E6",   "E6",   "E6",   "E6",   "E6",   "E6",   "E6",   "E6",   "E6",   "E6",   "E6",     "",
    "E7",   "E7",   "E7",   "E7",   "E7",   "E7",   "E7",   "E7",   "E7",   "E7",  "S27",   "E7",   "E7",   "E7",   "E7",   "E7",   "E7",   "E7",   "E7",   "E7",     "",
    "E8",   "E8",   "E8",  "S12",   "E8",   "E8",   "E8",   "E8",  "S10",  "S11",   "E8",   "E8",   "E8",  "S14",   "E8",  "S32",   "E8",   "E8",   "E8",   "E8",     "",
    "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",   "E9",  "S33",   "E9",   "E9",     "",
   "R3!",  "R3!",  "R3!",   "R3",  "R3!",  "R3!",  "R3!",  "R3!",   "R3",   "R3",  "R3!",  "R3!",  "R3!",   "R3",  "R3!",  "R3!",   "R3",  "R3!",  "R3!",  "R3!",     "",
   "E10",  "E10",  "S17",  "S18",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",  "E10",     "",
   "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "S35",     "",
   "E12",  "E12",  "E12",  "E12",  "E12",  "S37",  "S38",  "S39",  "E12",  "E12",  "E12",  "E12",  "E12",  "E12",  "E12",  "E12",  "E12",  "E12",  "E12",  "E12",     "",
  "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!", "R10!",  "R10",
  "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!", "R16!",  "R16",
  "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!", "R22!",  "R22",
   "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "S40",     "",
   "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "S41",     "",
  "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!", "R13!",  "R13",     "",
  "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!", "R14!",  "R14",     "",
  "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!", "R15!",  "R15",     "",
   "E13",  "E13",  "E13",  "S44",   "S45", "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",     "",
  "R23!", "R23!", "R23!",  "R23", "R23!", "R23!", "R23!", "R23!",  "R23",  "R23", "R23!", "R23!", "R23!",  "R23", "R23!",  "R23",  "R23", "R23!", "R23!", "R23!",     "",
    "E8",   "E8",   "E8",  "S12",   "E8",   "E8",   "E8",   "E8",  "S10",  "S11",   "E8",   "E8",   "E8",  "S14",   "E8",  "S32",   "E8",   "E8",   "E8",   "E8",     "",
    "E8",   "E8",   "E8",  "S12",   "E8",   "E8",   "E8",   "E8",  "S10",  "S11",   "E8",   "E8",   "E8",  "S14",   "E8",  "S32",   "E8",   "E8",   "E8",   "E8",     "",
    "E8",   "E8",   "E8",  "S12",   "E8",   "E8",   "E8",   "E8",  "S10",  "S11",   "E8",   "E8",   "E8",  "S14",   "E8",  "S32",   "E8",   "E8",   "E8",   "E8",     "",
  "R29!", "R29!", "R29!",  "R29", "R29!", "R29!", "R29!", "R29!",  "R29",  "R29", "R29!", "R29!", "R29!",  "R29", "R29!",  "R29",  "R29", "R29!", "R29!", "R29!",     "",
   "E13",  "E13",  "E13",  "S44",   "S45", "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",     "",
   "R4!",  "R4!",  "R4!",   "R4",  "R4!",  "R4!",  "R4!",  "R4!",   "R4",   "R4",  "R4!",  "R4!",  "R4!",   "R4",  "R4!",  "R4!",   "R4",  "R4!",  "R4!",  "R4!",     "",
   "R5!",  "R5!",  "R5!",   "R5",  "R5!",  "R5!",  "R5!",  "R5!",   "R5",   "R5",  "R5!",  "R5!",  "R5!",   "R5",  "R5!",  "R5!",   "R5",  "R5!",  "R5!",  "R5!",     "",
   "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "S51",     "",
   "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",  "R7!",   "R7",     "",
   "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",  "R8!",   "R8",     "",
   "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",  "R9!",   "R9",     "",
  "R11!", "R11!", "R11!",  "R11", "R11!", "R11!", "R11!", "R11!",  "R11",  "R11", "R11!", "R11!", "R11!",  "R11", "R11!",  "R11",  "R11", "R11!", "R11!", "R11!",     "",
  "R12!", "R12!", "R12!",  "R12", "R12!", "R12!", "R12!", "R12!",  "R12",  "R12", "R12!", "R12!", "R12!",  "R12", "R12!",  "R12",  "R12", "R12!", "R12!", "R12!",     "",
   "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "E11",  "S52",     "",
   "E14",  "E14",  "E14",  "E14",  "E14",  "E14",  "E14",  "E14",  "E14",  "E14",  "E14",  "S53",  "E14",  "E14",  "E14",  "E14",  "E14",  "E14",  "E14",  "R19",     "",
  "R20!", "R20!", "R20!", "R20!", "R20!", "R20!", "R20!", "R20!", "R20!", "R20!", "R20!",  "R20",  "R20", "R20!", "R20!", "R20!", "R20!", "R20!",  "R20",  "R20",     "",
  "R21!", "R21!", "R21!", "R21!", "R21!", "R21!", "R21!", "R21!", "R21!", "R21!", "R21!",  "R21",  "R21", "R21!", "R21!", "R21!", "R21!", "R21!",  "R21",  "R21",     "",
  "R26!", "R26!", "R26!",  "R26", "R26!", "R26!", "R26!", "R26!",  "R26",  "R26", "R26!", "R26!", "R26!",  "R26", "R26!",  "R26",  "R26", "R26!", "R26!", "R26!",     "",
  "R27!", "R27!", "R27!",  "R27", "R27!", "R27!", "R27!", "R27!",  "R27",  "R27", "R27!", "R27!", "R27!",  "R27", "R27!",  "R27",  "R27", "R27!", "R27!", "R27!",     "",
  "R28!", "R28!", "R28!",  "R28", "R28!", "R28!", "R28!", "R28!",  "R28",  "R28", "R28!", "R28!", "R28!",  "R28", "R28!",  "R28",  "R28", "R28!", "R28!", "R28!",     "",
    "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",   "E4",  "S54",   "E4",     "",
   "E15",  "E15",  "E15",  "E15",  "E15",  "E15",  "E15",  "E15",  "E15",  "E15",  "E15",  "E15",  "S55",  "E15",  "E15",  "E15",  "E15",  "E15",  "E15",  "E15",     "",
   "R6!",  "R6!",   "R6",   "R6",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",  "R6!",     "",
  "R17!", "R17!", "R17!",  "R17", "R17!", "R17!", "R17!", "R17!",  "R17",  "R17", "R17!", "R17!", "R17!",  "R17", "R17!",  "R17",  "R17", "R17!", "R17!", "R17!",     "",
   "E13",  "E13",  "E13",  "S44",  "S45",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",     "",
   "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "E16",  "S57",  "E16",  "E16",  "E16",  "E16",  "E16",     "",
   "E13",  "E13",  "E13",  "S44",  "S45",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",  "E13",     "",
  "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!", "R18!",  "R18",     "",
  "R24!", "R24!", "R24!",  "R24", "R24!", "R24!", "R24!", "R24!",  "R24",  "R24", "R24!", "R24!", "R24!",  "R24", "R24!",  "R24", "R24!", "R24!", "R24!", "R24!",     "",
  "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!", "R25!",  "R25", "R25!",     ""
};

string transition[TRANSITION_MAX_STATES][TRANSITION_MAX_NON_TERMINALS] = {
  "1",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",  "3",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",  "5",  "6",  "7",  "8", "13",   "",   "",   "",   "",   "",
   "",   "", "15", "16",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "", "19",  "6",  "7",  "8", "13",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "", "20",  "6",  "7",  "8", "13",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "", "21",  "6",  "7",  "8", "13",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "", "23",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "", "29", "30", "31", "13",   "",   "",   "",   "", "28",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "", "34", "16",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "", "36",   "",   "",   "",    "",  "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "", "42", "43",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "", "29", "30", "31", "13",   "",   "",   "",   "", "46",
   "",   "",   "",   "",   "",   "", "29", "30", "31", "13",   "",   "",   "",   "", "47",
   "",   "",   "",   "",   "",   "", "29", "30", "31", "13",   "",   "",   "",   "", "48",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "", "50", "49",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "", "56",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "", "58",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",
   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""
};

/* Variaveis globais */
map <string, pair <string, string> > symbol_table; // <Lexema, Token, Atributo>
vector <pair <string, pair <string, string> > > parser_stack; // <Token, Lexema, Atributo>
string lex;
string lastLex;
string token;
vector <string> Tx;
int line = 1;
int col = 1;
int state;
int lastState;
int x;
char buffer[255];
FILE *fd, *out, *out2, *fopen(), *fprintf();

/* Declaracoes de funcoes */
int symbol_to_charClass(char);
void error_lexical(int);
void error_syntatic(string);
string make_token(int);
void make_token_attr(string, string);
pair <string, pair <string, string> > scanner (void);
int token_to_code(string);
int nt_to_code(string);
pair <string, string> semantic(int);

/******************************************************************************/
/* main - driver principal */
int main(int argc, char **argv) {
  map <int, int> rhs_size; // |Beta|
  map <int, string> lhs; // <Num_Regra, LHS>
  map <int, string> Beta; // <Num_Regra, Beta>
  pair <string, pair <string, string> > terminal; // <Token, Lexema, Atributo>
  int a, s;
  string t;
  char byte;

  lhs[1]  = "P'";
  lhs[2]  = "P";
  lhs[3]  = "V";  
  lhs[4]  = "LV";
  lhs[5]  = "LV";
  lhs[6]  = "D";
  lhs[7]  = "TIPO";
  lhs[8]  = "TIPO";
  lhs[9]  = "TIPO";
  lhs[10] = "A";
  lhs[11] = "ES";
  lhs[12] = "ES";
  lhs[13] = "ARG";
  lhs[14] = "ARG";
  lhs[15] = "ARG";
  lhs[16] = "A";
  lhs[17] = "CMD";
  lhs[18] = "LD";
  lhs[19] = "LD";
  lhs[20] = "OPRD";
  lhs[21] = "OPRD";
  lhs[22] = "A";
  lhs[23] = "COND";
  lhs[24] = "CABECALHO";
  lhs[25] = "EXP_R";
  lhs[26] = "CORPO";
  lhs[27] = "CORPO";
  lhs[28] = "CORPO";
  lhs[29] = "CORPO";
  lhs[30] = "A";  

  Beta[1]  = "P";
  Beta[2]  = "inicio V A";
  Beta[3]  = "varinicio LV";  
  Beta[4]  = "D LV";
  Beta[5]  = "varfim;";
  Beta[6]  = "id TIPO;";
  Beta[7]  = "int";
  Beta[8]  = "real";
  Beta[9]  = "lit";
  Beta[10] = "ES A";
  Beta[11] = "leia id;";
  Beta[12] = "escreva ARG;";
  Beta[13] = "literal";
  Beta[14] = "num";
  Beta[15] = "id";
  Beta[16] = "CMD A";
  Beta[17] = "id rcb LD;";
  Beta[18] = "OPRD opm OPRD";
  Beta[19] = "OPRD";
  Beta[20] = "id";
  Beta[21] = "num";
  Beta[22] = "COND A";
  Beta[23] = "CABECALHO CORPO";
  Beta[24] = "se (EXP_R) entao";
  Beta[25] = "OPRD opr OPRD";
  Beta[26] = "ES CORPO";
  Beta[27] = "CMD CORPO";
  Beta[28] = "COND CORPO";
  Beta[29] = "fimse";
  Beta[30] = "fim"; 
  
  rhs_size[1]  = 1;  
  rhs_size[2]  = 3;
  rhs_size[3]  = 2;
  rhs_size[4]  = 2;
  rhs_size[5]  = 2;
  rhs_size[6]  = 3;
  rhs_size[7]  = 1;
  rhs_size[8]  = 1;
  rhs_size[9]  = 1;
  rhs_size[10] = 2;
  rhs_size[11] = 3;
  rhs_size[12] = 3;
  rhs_size[13] = 1;
  rhs_size[14] = 1;
  rhs_size[15] = 1;
  rhs_size[16] = 2;
  rhs_size[17] = 4;
  rhs_size[18] = 3;
  rhs_size[19] = 1;
  rhs_size[20] = 1;
  rhs_size[21] = 1;
  rhs_size[22] = 2;
  rhs_size[23] = 2;
  rhs_size[24] = 5;
  rhs_size[25] = 3;
  rhs_size[26] = 2;
  rhs_size[27] = 2;
  rhs_size[28] = 2;
  rhs_size[29] = 1;
  rhs_size[30] = 1;

  symbol_table["inicio"]     = make_pair("inicio", "");
  symbol_table["varinicio"]  = make_pair("varinicio", "");
  symbol_table["varfim"]     = make_pair("varfim", "");
  symbol_table["escreva"]    = make_pair("escreva", "");
  symbol_table["leia"]       = make_pair("leia", "");
  symbol_table["se"]         = make_pair("se", "");
  symbol_table["entao"]      = make_pair("entao", "");
  symbol_table["fimse"]      = make_pair("fimse", "");
  symbol_table["fim"]        = make_pair("fim", "");
  symbol_table["inteiro"]    = make_pair("inteiro", "int");
  symbol_table["literal"]    = make_pair("literal", "literal");
  symbol_table["real"]       = make_pair("real", "double");

  parser_stack.push_back(make_pair("0", make_pair("", "")));  

  if ((fd = fopen("texto.alg", "r")) == NULL) {
    cout << "Erro na abertura do programa fonte!\n";
  } else if ((out = fopen("out.c", "wb")) == NULL) {
    cout << "Erro na abertura do programa objeto!\n";
  } else {
    terminal = scanner();
    do {
      s = atoi(parser_stack.back().first.c_str());
      a = token_to_code(terminal.first);
      if (action[s][a][0] == 'S') {
        t = action[s][a].substr(1, 2);
        cout << terminal.first << ":" << terminal.second.first << ":" << symbol_table[terminal.second.first].second << endl;
        parser_stack.push_back(make_pair(terminal.first, make_pair(terminal.second.first, symbol_table[terminal.second.first].second)));
        parser_stack.push_back(make_pair(t, make_pair("", "")));
        terminal = scanner();
        //cout << terminal.first << ":" << terminal.second.first << endl;      
      } else if (action[s][a][0] == 'R') {
        int rule = atoi((action[s][a].substr(1, 2)).c_str());
        pair <string, string> p = semantic(rule);
        for (int i = 1; i <= 2 * rhs_size[rule]; i++) {
          pair <string, pair <string, string> > aux = parser_stack.back();
          //cout << aux.first << ":" << aux.second.first << ":" << aux.second.second << "   ";
          parser_stack.pop_back();
        }
        //cout << endl;
        t = parser_stack.back().first;
        string A = lhs[rule];
        parser_stack.push_back(make_pair(A, p));
        int u = atoi(t.c_str());
        int nt = nt_to_code(A);
        string new_state = transition[u][nt];
        parser_stack.push_back(make_pair(new_state, make_pair("", "")));
        //cout << A << " -> " << Beta[rule] << endl;
      } else if (action[s][a][0] == 'A') {
        cout << "Acc" << endl;
        break;
      } else {
        error_syntatic(action[s][a]);
      }
    } while (true);
  
    if ((out2 = fopen("out2.c", "wb")) == NULL) {
      cout << "Erro na abertura do programa objeto!\n";
    } else {
      fprintf(out2, "#include <stdio.h>\n\ntypedef char literal[256];\n\nint main() {\n");
      fprintf(out2, "\t/*----Variaveis temporarias----*/\n");
      for (vector <string>::iterator it = Tx.begin(); it != Tx.end(); it++) {
        fprintf(out2, "\t%s\n", it->c_str());
      }
      fprintf(out2, "\t/*-----------------------------*/\n");
      fclose(out);
      if ((out = fopen("out.c", "rb")) == NULL) {
        cout << "Erro na abertura do programa fonte!\n";
      } else {
        while (!feof(out)) {
          fread(&byte, sizeof(char), 1, out);
          fwrite(&byte, sizeof(char), 1, out2);
        }
      }
      fprintf(out2, "\treturn 0;\n}\n");
      fclose(out);
      fclose(out2);
    }
  }
  return 0;
}

/******************************************************************************/
/* scanner - funcao que realiza a analise lexica de programas MDPgol e retorna o
             pair <token, lexema, atributo> */
pair <string, pair <string, string> > scanner() {
  pair <string, pair <string, string> > nextToken;
  char nextChar;
  int charClass;
  nextChar = getc(fd);
  col++;  
  if (nextChar == '\n') {
    line++;
    col = 1;
  }
  charClass = symbol_to_charClass(nextChar);
  state = sigma[state][charClass];
  if (state < 0) {
    printf("texto.alg:%d:%d erro: ", line, col);
    error_lexical(state);
    exit(EXIT_FAILURE);
  } else if (state > 0) {
    lex.push_back(nextChar);
    lastState = state;
  } else {
    if (lex.size() >= 1) {
      token = make_token(lastState);
      if (!symbol_table.count(lex)) {
        if (token == "opr") {
          if (lex == "=") {
            symbol_table[lex] = make_pair(token, "==");
          } else if (lex == "<>") {
            symbol_table[lex] = make_pair(token, "!=");            
          } else {
            symbol_table[lex] = make_pair(token, lex);            
          }
        } else if (token == "rcb") {
          symbol_table[lex] = make_pair(token, "=");
        } else if (token == "id") {
          symbol_table[lex] = make_pair(token, "");
          // cout << "inserindo: <" << token << ", " << lex << ">\n";          
        } else {
          symbol_table[lex] = make_pair(token, lex);          
        }
        lastLex = lex;
        //cout << symbol_table[lex].first << ":" << lex << ":" << symbol_table[lex].second << endl;
      }
      if (lastState == 9) { // ID
        if (lex == "inteiro" || lex == "literal" || lex == "real") {
          //cout << "atribuindo: <" << token << ", " << lastLex << ", " << lex << ">\n";          
          if (symbol_table[lex].first == lex) token = lex;          
          symbol_table[lastLex].second = lex;
        }
      }
      if (lastState == 1 || lastState == 3 || lastState == 6) { // num
        size_t found = lex.find(".");
        if (found != string::npos) {
          symbol_table[lastLex].second = "real";
        } else {
          symbol_table[lastLex].second = "inteiro";
        }
      }
      if (symbol_table[lex].first == lex) {
        token = lex;
        // cout << "existente: <" << symbol_table[lex].first << ", " << lex << ", " << symbol_table[lex].second << ">\n";
      }
      nextToken = make_pair(token, make_pair(lex, ""));
      lex.clear();
      if (sigma[state][charClass] > 0) {
        state = sigma[state][charClass];
        lex.push_back(nextChar);
        lastState = state;
      } else if (sigma[state][charClass] < 0) {
        state = sigma[state][charClass];        
        printf("texto.alg:%d:%d erro: ", line, col);
        error_lexical(state);
        exit(EXIT_FAILURE);
      }
      return nextToken;    
    }
  }
  nextToken = scanner();
  return nextToken;
}

/******************************************************************************/
/* symbol_to_charClass - funcao que recebe um caractere da entrada e determina
                         sua classe de caractere */
int symbol_to_charClass(char c) {
  if (c == '\t') {
    return 0;
  } else if (c == '\n') {
    return 1;
  } else if (c == ' ') {
    return 2;
  } else if (c == '"') {
    return 3;
  } else if (c >= '(' && c <= '+') {
    return c - 36;
  } else if (c >= '-' && c <= '/') {
    return c - 37;
  } else if (c >= '0' && c <= '9') {
    return 11;
  } else if (c >= ';' && c <= '>') {
    return c - 47;
  } else if ((c >= 'A' && c <= 'Z') || ((c >= 'a' && c <= 'z'))) {
    return c != 'E' ? 16 : 17;
  } else if (c == '_') {
    return 18;
  } else if (c == '{') {
    return 19;
  } else if (c == '}') {
    return 20;
  } else if (c == EOF) {
    return 21;
  } else {
    return 22;
  }
}

/******************************************************************************/
/* token_to_code - funcao que recebe um token do fluxo de tokens retornados pelo
                   scanner e retorna seu codigo interno */
int token_to_code(string t) {
  if (t == "inicio") return 0;
  if (t == "varinicio") return 1;
  if (t == "varfim") return 2;
  if (t == "id") return 3;
  if (t == "num") return 4;
  if (t == "inteiro") return 5;
  if (t == "real") return 6;
  if (t == "literal") return 7;
  if (t == "leia") return 8;
  if (t == "escreva") return 9;
  if (t == "rcb") return 10;
  if (t == "opm") return 11;
  if (t == "opr") return 12;
  if (t == "se") return 13;
  if (t == "entao") return 14;
  if (t == "fimse") return 15;
  if (t == "fim") return 16;
  if (t == "(") return 17;
  if (t == ")") return 18;
  if (t == ";") return 19;
  else return 20;
}

/******************************************************************************/
/* nt_to_code - funcao que recebe um nao-terminal da gramatica do MDPgol e 
                retorna seu codigo interno */
int nt_to_code(string nt) {
  if (nt == "P") return 0;
  if (nt == "V") return 1;
  if (nt == "LV") return 2;
  if (nt == "D") return 3;
  if (nt == "TIPO") return 4;
  if (nt == "A") return 5;
  if (nt == "ES") return 6;
  if (nt == "CMD") return 7;
  if (nt == "COND") return 8;
  if (nt == "CABECALHO") return 9;
  if (nt == "ARG") return 10;
  if (nt == "LD") return 11;
  if (nt == "OPRD") return 12;
  if (nt == "EXP_R") return 13;
  else return 14;
}                

/******************************************************************************/
/* error_lexical - funcao que indica que o scanner encontrou um lexema fora do
                padrao especificado */
void error_lexical(int code) {
  if (code == -1) cout << "token iniciado por '.'" << endl;
  if (code == -2) cout << "token iniciado por '_'" << endl;
  if (code == -3) cout << "token '}' sem um token '{' anterior" << endl;
  if (code == -4) cout << "caractere invalido" << endl;
  if (code == -5) cout << "esperado um token 'Num' (digito)" << endl;
  if (code == -6) cout << "esperado tokens '+', '-' ou 'Num' (digito) depois do 'E'" << endl;
  if (code == -7) cout << "esperado um token 'Num' (digito)" << endl;
  if (code == -8) cout << "esperado um token '\"' para fechar o ultimo token '\"'" << endl;
  if (code == -9) cout << "esperado um token '}' para fechar o ultimo token '{'" << endl;
}

/******************************************************************************/
/* error_syntatic - funcao que indica que o scanner encontrou um lexema fora do
                padrao especificado */
void error_syntatic(string E) {
  printf("texto.alg:%d:%d erro: ", line, col);
  if (E == "E0") cout << "inicio nao encontrado" << endl;
  if (E == "E1") cout << "estrutura incompleta - esperado fim de sentenca" << endl;
  if (E == "E2") cout << "varinicio nao encontrado" << endl;
  if (E == "E3") cout << "erro no bloco de comandos" << endl;
  if (E == "E4") cout << "estrutura incompleta - esperado fecha parenteses" << endl;
  if (E == "E5") cout << "estrutura incompleta - esperado id" << endl;
  if (E == "E6") cout << "estrutura incompleta - esperado id, numero ou literal" << endl;
  if (E == "E7") cout << "estrutura incompleta - esperado operador de atribuicao" << endl;
  if (E == "E8") cout << "erro no bloco do entao" << endl;
  if (E == "E9") cout << "estrutura incompleta - esperado abre parenteses" << endl;
  if (E == "E10") cout << "estrutura incompleta - esperado id ou varfim" << endl;
  if (E == "E11") cout << "estrutura incompleta - esperado ponto e virgula" << endl;
  if (E == "E12") cout << "estrutura incompleta - esperado um tipo" << endl;
  if (E == "E13") cout << "estrutura incompleta - esperado id ou numero" << endl;
  if (E == "E14") cout << "estrutura incompleta - esperado ponto e virgula ou operador aritmetico" << endl;
  if (E == "E15") cout << "estrutura incompleta - esperado operador relacional" << endl;
  if (E == "E16") cout << "estrutura incompleta - esperado entao" << endl;
  exit(EXIT_FAILURE);
}

/******************************************************************************/
/* make_token - funcao que recebe um estado de aceitacao e retorna o token
                representado por esse estado */
inline string make_token(int s) {
  if (s == 1 || s == 3 || s == 6) {
    return "num";
  } else if (s == 8) {
    return "literal";
  } else if (s == 9) {
    return "id";
  } else if (s == 11) {
    return "comentario";
  } else if (s == 12) {
    return "$";
  } else if (s == 13 || s == 14 || s == 15 || s == 16) {
    return "opr";
  } else if (s == 17) {
    return "rcb";
  } else if (s == 18) {
    return "opm";
  } else if (s == 19) {
    return "(";
  } else if (s == 20) {
    return ")";
  } else if (s == 21) {
    return ";";
  } else {
    return "erro";
  }
}

pair <string, string> semantic(int rule) {
  // cout << "rule: " << rule << endl;
  pair <string, pair <string, string> > symbol, symbol2;
  pair <string, string> p;
  if (rule == 5) {
    fprintf(out, "\n\n\n");
  } else if (rule == 6) {
    // id.tipo <- TIPO.tipo;
    symbol = parser_stack.end()[-4];
    p.first = symbol.second.first;
    p.second = symbol.second.second;
    symbol = parser_stack.end()[-6];
    // Imprimir ( TIPO.tipo id.lexema ; )
    //cout << p.second << ":" << symbol.second.first << endl;
    fprintf(out, "\t%s %s;\n", p.second.c_str(), symbol.second.first.c_str());
    return p;
  } else if ((rule >= 7 && rule <= 9) || (rule == 13 || rule == 14 || rule == 19 || rule == 21)) {
    symbol = parser_stack.end()[-2];
    p.first = symbol.second.first;
    p.second = symbol.second.second;
    return p;
  } else if (rule == 11) {
    symbol = parser_stack.end()[-4];
    if (symbol.second.second != "") {
      if (symbol.second.second == "literal") {
        fprintf(out, "\tscanf(\"%%s\", %s);\n", symbol.second.first.c_str());
      } else if (symbol.second.second == "inteiro") {
        fprintf(out, "\tscanf(\"%%d\", &%s);\n", symbol.second.first.c_str());
      } else if (symbol.second.second == "real") {
        fprintf(out, "\tscanf(\"%%lf\", &%s);\n", symbol.second.first.c_str());
      }
    } else {
      printf("texto.alg:%d:%d Erro identificado na analise semantica: ", line, col);      
      cout << "erro: variavel nao declarada." << endl;
      exit(EXIT_FAILURE);
    }
  } else if (rule == 12) {
    symbol = parser_stack.end()[-4];
    fprintf(out, "\tprintf(%s);\n", symbol.second.first.c_str());
  } else if (rule == 15) {
    symbol = parser_stack.end()[-2];
    if (symbol.second.second != "") {
      p.first = symbol.second.first;
      p.second = symbol.second.second;
      return p;
    } else {
      printf("texto.alg:%d:%d Erro identificado na analise semantica: ", line, col);    
      cout << "erro: variavel nao declarada." << endl;
      exit(EXIT_FAILURE);      
    }
  } else if (rule == 17) {
    symbol = parser_stack.end()[-8];
    string rcb = parser_stack.end()[-6].second.second;
    string ld_tipo = parser_stack.end()[-4].second.second;
    string ld_lex = parser_stack.end()[-4].second.first;
    if (symbol.second.second != "") {
      // cout << symbol.second.second << "***" << ld << endl;
      if (symbol.second.second == ld_tipo) {
        fprintf(out, "\t%s %s %s;\n", symbol.second.first.c_str(), rcb.c_str(), ld_lex.c_str());
      } else {
        printf("texto.alg:%d:%d Erro identificado na analise semantica: ", line, col);
        cout << "erro: tipos diferentes para atribuicao." << endl;
        exit(EXIT_FAILURE);        
      }
    } else {
      printf("texto.alg:%d:%d Erro identificado na analise semantica: ", line, col);  
      cout << "erro: variavel nao declarada." << endl;
      exit(EXIT_FAILURE);      
    }
  } else if (rule == 18 || rule == 25) {
    symbol = parser_stack.end()[-4];
    pair <string, pair <string, string> > oprd1 = parser_stack.end()[-6];
    pair <string, pair <string, string> > oprd2 = parser_stack.end()[-2];
    cout << oprd1.second.second << ":" << oprd2.second.second << endl;
    if (oprd1.second.second == oprd2.second.second) {
      string T = "T" + string(itoa(x, buffer, 10));
      x++;
      Tx.push_back("int " + T + ";");
      p.first = T;
      p.second = oprd1.second.second;
      fprintf(out, "\t%s = %s %s %s;\n", T.c_str(), oprd1.second.first.c_str(), symbol.second.first.c_str(), oprd2.second.first.c_str());
      return p;
    } else {
      printf("texto.alg:%d:%d Erro identificado na analise semantica: ", line, col);  
      cout << "erro: operandos com tipos incompativeis." << endl;
      exit(EXIT_FAILURE); 
    }
  } else if (rule == 20) {
    symbol = parser_stack.end()[-2];
    if (symbol.second.second != "") {
      p.first = symbol.second.first;
      p.second = symbol.second.second;
      return p;
    } else {
      printf("texto.alg:%d:%d Erro identificado na analise semantica: ", line, col);
      cout << "erro: variavel nao declarada." << endl;
      exit(EXIT_FAILURE);      
    }
  } else if (rule == 23) {
    fprintf(out, "\t}\n");
  } else if (rule == 24) {
    symbol = parser_stack.end()[-6];
    fprintf(out, "\tif (%s) {\n", symbol.second.first.c_str());
  }
}