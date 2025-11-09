#define C_LIGHT_RED   200,  60,  30
#define C_LIGHT_PINK  255, 220, 200
#define C_LIGHT_GREEN 105, 255,  65
#define C_LIGHT_BLUE   55, 105, 255
#define C_PURPLE      255,  55, 255
#define C_ORANGE      255, 100,  20
#define C_BLUE          0,  55, 255
#define C_RED         255,  55,   0
#define C_GREEN         0, 255,  55
#define C_BLACK         0,   0,   0
#define C_EMERALD     155, 255,  55


#define C_ALP       {C_LIGHT_RED}
#define C_MOD       {C_LIGHT_GREEN}
#define C_NUM       {C_LIGHT_BLUE}
#define C_NAV       {C_PURPLE}
#define C_SYM       {C_ORANGE}
#define C_FUN       {C_BLUE}
#define C_NON       {C_BLACK}
#define C_LAY       {C_EMERALD}
#define C_UND       {C_LIGHT_RED}

enum layers {
    _BASE = 0,
    _NAV,
    _NUM,
    _SYM,
    _FUNCTION,
    _ALT,
};

// Macro to map physical order to led index
#define LAYOUT_COLORS(\
    K00, K01, K02, K03, K04, K05,                         K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,                         K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,                         K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33, K34, K35, K36, K37,     K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, \
                   K40, K41, K42, K43, K44,     K45, K46, K47, K48, K49, \
    U00, U01, U02, U03, U04, U05,                         U06, U07, U08, U09, U0A, U0B \
) \
{ \
    U00, U01, U02, U03, U04, U05, \
    K44, K43, K42, K41, K40, \
    K37, K36, K35, K34, K33, K32, K31, K30, \
    K25, K24, K23, K22, K21, K20, \
    K15, K14, K13, K12, K11, K10, \
    K05, K04, K03, K02, K01, K00, \
    U06, U07, U08, U09, U0A, U0B, \
    K45, K46, K47, K48, K49, \
    K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, \
    K26, K27, K28, K29, K2A, K2B, \
    K16, K17, K18, K19, K1A, K1B, \
    K06, K07, K08, K09, K0A, K0B \
}


const uint8_t PROGMEM layer_colors[5][RGB_MATRIX_LED_COUNT][3] = {
    // Layer 0: Base
    [_BASE] = LAYOUT_COLORS(
    C_NAV, C_NUM, C_NUM, C_NUM, C_NUM, C_NUM,                                   C_NUM, C_NUM, C_NUM, C_NUM, C_NUM, C_NAV,
    C_NAV, C_ALP, C_ALP, C_ALP, C_ALP, C_ALP,                                   C_ALP, C_ALP, C_ALP, C_ALP, C_ALP, C_NAV,
    C_MOD, C_ALP, C_ALP, C_ALP, C_ALP, C_ALP,                                   C_ALP, C_ALP, C_ALP, C_ALP, C_ALP, C_MOD,
    C_MOD, C_ALP, C_ALP, C_ALP, C_ALP, C_ALP, C_SYM, C_MOD,       C_LAY, C_SYM, C_ALP, C_ALP, C_ALP, C_ALP, C_ALP, C_MOD,
                         C_LAY, C_MOD, C_NAV, C_NAV, C_LAY,       C_LAY, C_NAV, C_MOD, C_MOD, C_MOD, 
    C_UND, C_UND, C_UND, C_UND, C_UND, C_UND,                                   C_UND, C_UND, C_UND, C_UND, C_UND, C_UND                         
    ),

    // Layer 1: Nav
    [_NAV] = LAYOUT_COLORS(
    C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,                                   C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,
    C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,                                   C_NAV, C_NAV, C_NAV, C_NAV, C_NAV, C_NAV,
    C_NON, C_MOD, C_MOD, C_MOD, C_MOD, C_NON,                                   C_NAV, C_NAV, C_NAV, C_NAV, C_NAV, C_NAV,
    C_NON, C_NON, C_MOD, C_NON, C_NON, C_NON, C_NON, C_MOD,       C_LAY, C_SYM, C_NAV, C_NAV, C_NAV, C_NAV, C_NAV, C_NAV,
                         C_LAY, C_MOD, C_NAV, C_NAV, C_LAY,       C_LAY, C_NAV, C_MOD, C_MOD, C_MOD, 
    C_UND, C_UND, C_UND, C_UND, C_UND, C_UND,                                   C_UND, C_UND, C_UND, C_UND, C_UND, C_UND                         
    ),

    // Layer 2: Num
    [_NUM] = LAYOUT_COLORS(
    C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,                                   C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,
    C_NON, C_SYM, C_NUM, C_NUM, C_NUM, C_SYM,                                   C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,
    C_NON, C_SYM, C_NUM, C_NUM, C_NUM, C_SYM,                                   C_NON, C_MOD, C_MOD, C_MOD, C_MOD, C_NON,
    C_NON, C_SYM, C_NUM, C_NUM, C_NUM, C_NUM, C_NON, C_MOD,       C_LAY, C_SYM, C_NON, C_NON, C_NON, C_MOD, C_NON, C_NON,
                         C_LAY, C_MOD, C_NAV, C_NAV, C_LAY,       C_LAY, C_NAV, C_MOD, C_MOD, C_MOD, 
    C_UND, C_UND, C_UND, C_UND, C_UND, C_UND,                                   C_UND, C_UND, C_UND, C_UND, C_UND, C_UND                         
    ),

    // Layer 3: Sym
    [_SYM] = LAYOUT_COLORS(
    C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,                                   C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,
    C_NON, C_SYM, C_SYM, C_SYM, C_SYM, C_SYM,                                   C_SYM, C_SYM, C_SYM, C_SYM, C_SYM, C_NON,
    C_NON, C_SYM, C_SYM, C_SYM, C_SYM, C_SYM,                                   C_SYM, C_SYM, C_SYM, C_SYM, C_SYM, C_NON,
    C_NON, C_SYM, C_SYM, C_SYM, C_SYM, C_SYM, C_NON, C_MOD,       C_LAY, C_SYM, C_SYM, C_SYM, C_SYM, C_SYM, C_SYM, C_NON,
                         C_LAY, C_MOD, C_NAV, C_NAV, C_LAY,       C_LAY, C_NAV, C_MOD, C_MOD, C_MOD, 
    C_UND, C_UND, C_UND, C_UND, C_UND, C_UND,                                   C_UND, C_UND, C_UND, C_UND, C_UND, C_UND                         
    ),

    // Layer 4: Fun
    [_FUNCTION] = LAYOUT_COLORS(
    C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,                                   C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,
    C_NON, C_NON, C_NON, C_NON, C_NON, C_NON,                                   C_NON, C_FUN, C_FUN, C_FUN, C_FUN, C_NON,
    C_NON, C_MOD, C_MOD, C_MOD, C_MOD, C_NON,                                   C_NON, C_FUN, C_FUN, C_FUN, C_FUN, C_NON,
    C_NON, C_NON, C_MOD, C_NON, C_NON, C_NON, C_NON, C_MOD,       C_LAY, C_SYM, C_NON, C_FUN, C_FUN, C_FUN, C_FUN, C_NON,
                         C_LAY, C_MOD, C_NAV, C_NAV, C_LAY,       C_LAY, C_NAV, C_MOD, C_MOD, C_MOD, 
    C_UND, C_UND, C_UND, C_UND, C_UND, C_UND,                                   C_UND, C_UND, C_UND, C_UND, C_UND, C_UND                         
    )

};