<?php

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
////                                                       ////
////    functions are basically large switch statements    ////
////                                                       ////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

function gen_question($type)
{
    $question    = "";
    $numerator   = "";
    $denominator = "";
    $q_out = array();
    if ($type == 1)
    {
        $q_out = gen_1();
    }
    else if ($type == 2)
    {
        $q_out = gen_2();
    }
    else if ($type == 3)
    {
        $q_out = gen_3();
    }
    else if ($type == 4)
    {
        $q_out = gen_4();
    }
    else if ($type == 5)
    {
        $q_out = gen_5();
    }
    else if ($type == 6)
    {
        $q_out = gen_6();
    }
    else if ($type == 7)
    {
        $q_out = gen_7();
    }
    else if ($type == 8)
    {
        $q_out = gen_8();
    }
    else if ($type == 9)
    {
        $q_out = gen_9();
    }
    else if ($type == 10)
    {
        $q_out = gen_10();
    }
    else if ($type == 11)
    {
        $q_out = gen_11();
    }
    else if ($type == 12)
    {
        $q_out = gen_12();
    }
    else if ($type == 13)
    {
        $q_out = gen_13();
    }
    else if ($type == 14)
    {
        $q_out = gen_14();
    }
    else if ($type == 15)
    {
        $q_out = gen_15();
    }
    else if ($type == 16)
    {
        $q_out = gen_16();
    }
    else if ($type == 17)
    {
        $q_out = gen_17();
    }
    else if ($type == 18)
    {
        $q_out = gen_18();
    }
    else if ($type == 19)
    {
        $q_out = gen_19();
    }
    else if ($type == 20)
    {
        $q_out = gen_20();
    }
    else if ($type == 21)
    {
        $q_out = gen_21();
    }
    else if ($type == 22)
    {
        $q_out = gen_22();
    }
    else if ($type == 23)
    {
        $q_out = gen_23();
    }
    else if ($type == 24)
    {
        $q_out = gen_24();
    }
    else if ($type == 25)
    {
        $q_out = gen_25();
    }
    else if ($type == 26)
    {
        $q_out = gen_26();
    }
    else if ($type == 27)
    {
        $q_out = gen_27();
    }
    else if ($type == 28)
    {
        $q_out = gen_28();
    }
    else if ($type == 29)
    {
        $q_out = gen_29();
    }
    else if ($type == 30)
    {
        $q_out = gen_30();
    }
    else if ($type == 31)
    {
        $q_out = gen_31();
    }
    else if ($type == 32)
    {
        $q_out = gen_32();
    }
    else if ($type == 33)
    {
        $q_out = gen_33();
    }
    else if ($type == 34)
    {
        $q_out = gen_34();
    }
    else if ($type == 35)
    {
        $q_out = gen_35();
    }
    else if ($type == 36)
    {
        $q_out = gen_36();
    }
    else if ($type == 37)
    {
        $q_out = gen_37();
    }
    else if ($type == 38)
    {
        $q_out = gen_38();
    }
    else if ($type == 39)
    {
        $q_out = gen_39();
    }
    else if ($type == 40)
    {
        $q_out = gen_40();
    }
    else if ($type == 41)
    {
        $q_out = gen_41();
    }
    else if ($type == 42)
    {
        $q_out = gen_42();
    }
    else if ($type == 43)
    {
        $q_out = gen_43();
    }
    else if ($type == 44)
    {
        $q_out = gen_44();
    }
    else if ($type == 45)
    {
        $q_out = gen_45();
    }
    else if ($type == 46)
    {
        $q_out = gen_46();
    }
    else if ($type == 47)
    {
        $q_out = gen_47();
    }
    else if ($type == 48)
    {
        $q_out = gen_48();
    }
    else if ($type == 49)
    {
        $q_out = gen_49();
    }
    else if ($type == 50)
    {
        $q_out = gen_50();
    }
    else if ($type == 51)
    {
        $q_out = gen_51();
    }
    else if ($type == 52)
    {
        $q_out = gen_52();
    }
    else if ($type == 53)
    {
        $q_out = gen_53();
    }
    else if ($type == 54)
    {
        $q_out = gen_54();
    }
    else if ($type == 55)
    {
        $q_out = gen_55();
    }
    else if ($type == 56)
    {
        $q_out = gen_56();
    }
    else if ($type == 57)
    {
        $q_out = gen_57();
    }
    else if ($type == 58)
    {
        $q_out = gen_58();
    }
    else if ($type == 59)
    {
        $q_out = gen_59();
    }
    else if ($type == 60)
    {
        $q_out = gen_60();
    }
    else if ($type == 61)
    {
        $q_out = gen_61();
    }
    else if ($type == 62)
    {
        $q_out = gen_62();
    }
    else if ($type == 63)
    {
        $q_out = gen_63();
    }
    else if ($type == 64)
    {
        $q_out = gen_64();
    }
    else if ($type == 65)
    {
        $q_out = gen_65();
    }
    else if ($type == 66)
    {
        $q_out = gen_66();
    }
    else if ($type == 67)
    {
        $q_out = gen_67();
    }
    else if ($type == 68)
    {
        $q_out = gen_68();
    }
    else if ($type == 69)
    {
        $q_out = gen_69();
    }
    else if ($type == 70)
    {
        $q_out = gen_70();
    }
    else if ($type == 71)
    {
        $q_out = gen_71();
    }
    else if ($type == 72)
    {
        $q_out = gen_72();
    }
    else if ($type == 73)
    {
        $q_out = gen_73();
    }
    else if ($type == 74)
    {
        $q_out = gen_74();
    }
    else if ($type == 75)
    {
        $q_out = gen_75();
    }
    else if ($type == 76)
    {
        $q_out = gen_76();
    }
    else if ($type == 77)
    {
        $q_out = gen_77();
    }
    else if ($type == 78)
    {
        $q_out = gen_78();
    }
    else if ($type == 79)
    {
        $q_out = gen_79();
    }
    else if ($type == 80)
    {
        $q_out = gen_80();
    }
    else if ($type == 81)
    {
        $q_out = gen_81();
    }
    else if ($type == 82)
    {
        $q_out = gen_82();
    }
    else if ($type == 83)
    {
        $q_out = gen_83();
    }
    else if ($type == 84)
    {
        $q_out = gen_84();
    }
    else if ($type == 85)
    {
        $q_out = gen_85();
    }
    else if ($type == 86)
    {
        $q_out = gen_86();
    }
    else if ($type == 87)
    {
        $q_out = gen_87();
    }
    else if ($type == 88)
    {
        $q_out = gen_88();
    }
    else if ($type == 89)
    {
        $q_out = gen_89();
    }
    else if ($type == 90)
    {
        $q_out = gen_90();
    }
    else if ($type == 91)
    {
        $q_out = gen_91();
    }
    else if ($type == 92)
    {
        $q_out = gen_92();
    }
    else if ($type == 93)
    {
        $q_out = gen_93();
    }
    else if ($type == 94)
    {
        $q_out = gen_94();
    }
    else if ($type == 95)
    {
        $q_out = gen_95();
    }
    else if ($type == 96)
    {
        $q_out = gen_96();
    }
    else if ($type == 97)
    {
        $q_out = gen_97();
    }
    else if ($type == 98)
    {
        $q_out = gen_98();
    }
    else if ($type == 99)
    {
        $q_out = gen_99();
    }
    else if ($type == 100)
    {
        $q_out = gen_100();
    }
    else if ($type == 101)
    {
        $q_out = gen_101();
    }
    else if ($type == 102)
    {
        $q_out = gen_102();
    }
    else if ($type == 103)
    {
        $q_out = gen_103();
    }
    else if ($type == 104)
    {
        $q_out = gen_104();
    }
    else if ($type == 105)
    {
        $q_out = gen_105();
    }
    else if ($type == 106)
    {
        $q_out = gen_106();
    }
    else if ($type == 107)
    {
        $q_out = gen_107();
    }
    else if ($type == 108)
    {
        $q_out = gen_108();
    }
    else if ($type == 109)
    {
        $q_out = gen_109();
    }
    else if ($type == 110)
    {
        $q_out = gen_110();
    }
    else if ($type == 111)
    {
        $q_out = gen_111();
    }
    else if ($type == 112)
    {
        $q_out = gen_112();
    }
    else if ($type == 113)
    {
        $q_out = gen_113();
    }
    else if ($type == 114)
    {
        $q_out = gen_114();
    }
    else if ($type == 115)
    {
        $q_out = gen_115();
    }
    else if ($type == 116)
    {
        $q_out = gen_116();
    }
    else if ($type == 117)
    {
        $q_out = gen_117();
    }
    else if ($type == 118)
    {
        $q_out = gen_118();
    }
    else if ($type == 119)
    {
        $q_out = gen_119();
    }
    else if ($type == 120)
    {
        $q_out = gen_120();
    }
    else if ($type == 121)
    {
        $q_out = gen_121();
    }
    else if ($type == 122)
    {
        $q_out = gen_122();
    }
    else if ($type == 123)
    {
        $q_out = gen_123();
    }
    else if ($type == 124)
    {
        $q_out = gen_124();
    }
    else if ($type == 125)
    {
        $q_out = gen_125();
    }
    else if ($type == 126)
    {
        $q_out = gen_126();
    }
    else if ($type == 127)
    {
        $q_out = gen_127();
    }
    else if ($type == 128)
    {
        $q_out = gen_128();
    }
    else if ($type == 129)
    {
        $q_out = gen_129();
    }
    else if ($type == 130)
    {
        $q_out = gen_130();
    }
    else if ($type == 131)
    {
        $q_out = gen_131();
    }
    else if ($type == 132)
    {
        $q_out = gen_132();
    }
    else if ($type == 133)
    {
        $q_out = gen_133();
    }
    else if ($type == 134)
    {
        $q_out = gen_134();
    }
    else if ($type == 135)
    {
        $q_out = gen_135();
    }
    else if ($type == 136)
    {
        $q_out = gen_136();
    }
    else if ($type == 137)
    {
        $q_out = gen_137();
    }
    else if ($type == 138)
    {
        $q_out = gen_138();
    }
    else if ($type == 139)
    {
        $q_out = gen_139();
    }
    else if ($type == 140)
    {
        $q_out = gen_140();
    }
    else if ($type == 141)
    {
        $q_out = gen_141();
    }
    else if ($type == 142)
    {
        $q_out = gen_142();
    }
    else if ($type == 143)
    {
        $q_out = gen_143();
    }
    else if ($type == 144)
    {
        $q_out = gen_144();
    }
    else if ($type == 145)
    {
        $q_out = gen_145();
    }
    else if ($type == 146)
    {
        $q_out = gen_146();
    }
    else if ($type == 147)
    {
        $q_out = gen_147();
    }
    else if ($type == 148)
    {
        $q_out = gen_148();
    }
    else if ($type == 149)
    {
        $q_out = gen_149();
    }
    else if ($type == 150)
    {
        $q_out = gen_150();
    }
    else if ($type == 151)
    {
        $q_out = gen_151();
    }
    else if ($type == 152)
    {
        $q_out = gen_152();
    }
    else if ($type == 153)
    {
        $q_out = gen_153();
    }
    else if ($type == 154)
    {
        $q_out = gen_154();
    }
    else if ($type == 155)
    {
        $q_out = gen_155();
    }
    else if ($type == 156)
    {
        $q_out = gen_156();
    }
    else if ($type == 157)
    {
        $q_out = gen_157();
    }
    else if ($type == 158)
    {
        $q_out = gen_158();
    }
    else if ($type == 159)
    {
        $q_out = gen_159();
    }
    else if ($type == 160)
    {
        $q_out = gen_160();
    }
    else if ($type == 161)
    {
        $q_out = gen_161();
    }
    else if ($type == 162)
    {
        $q_out = gen_162();
    }
    else if ($type == 163)
    {
        $q_out = gen_163();
    }
    else if ($type == 164)
    {
        $q_out = gen_164();
    }
    else if ($type == 165)
    {
        $q_out = gen_165();
    }
    else if ($type == 166)
    {
        $q_out = gen_166();
    }
    else if ($type == 167)
    {
        $q_out = gen_167();
    }
    else if ($type == 168)
    {
        $q_out = gen_168();
    }
    else if ($type == 169)
    {
        $q_out = gen_169();
    }
    else if ($type == 170)
    {
        $q_out = gen_170();
    }
    else if ($type == 171)
    {
        $q_out = gen_171();
    }
    else if ($type == 172)
    {
        $q_out = gen_172();
    }
    else if ($type == 173)
    {
        $q_out = gen_173();
    }
    else if ($type == 174)
    {
        $q_out = gen_174();
    }
    else if ($type == 175)
    {
        $q_out = gen_175();
    }
    else if ($type == 176)
    {
        $q_out = gen_176();
    }
    else if ($type == 177)
    {
        $q_out = gen_177();
    }
    else if ($type == 178)
    {
        $q_out = gen_178();
    }
    else if ($type == 179)
    {
        $q_out = gen_179();
    }
    else if ($type == 180)
    {
        $q_out = gen_180();
    }
    else if ($type == 181)
    {
        $q_out = gen_181();
    }
    else if ($type == 182)
    {
        $q_out = gen_182();
    }
    else if ($type == 183)
    {
        $q_out = gen_183();
    }
    else if ($type == 184)
    {
        $q_out = gen_184();
    }
    else if ($type == 185)
    {
        $q_out = gen_185();
    }
    else if ($type == 186)
    {
        $q_out = gen_186();
    }
    else if ($type == 187)
    {
        $q_out = gen_187();
    }
    else if ($type == 188)
    {
        $q_out = gen_188();
    }
    else if ($type == 189)
    {
        $q_out = gen_189();
    }
    else if ($type == 190)
    {
        $q_out = gen_190();
    }
    else if ($type == 191)
    {
        $q_out = gen_191();
    }
    else if ($type == 192)
    {
        $q_out = gen_192();
    }
    else if ($type == 193)
    {
        $q_out = gen_193();
    }
    else if ($type == 194)
    {
        $q_out = gen_194();
    }
    else if ($type == 195)
    {
        $q_out = gen_195();
    }
    else if ($type == 196)
    {
        $q_out = gen_196();
    }
    else if ($type == 197)
    {
        $q_out = gen_197();
    }
    else if ($type == 198)
    {
        $q_out = gen_198();
    }
    else if ($type == 199)
    {
        $q_out = gen_199();
    }
    else if ($type == 200)
    {
        $q_out = gen_200();
    }
    else if ($type == 201)
    {
        $q_out = gen_201();
    }
    else if ($type == 202)
    {
        $q_out = gen_202();
    }
    else if ($type == 203)
    {
        $q_out = gen_203();
    }
    else if ($type == 204)
    {
        $q_out = gen_204();
    }
    else if ($type == 205)
    {
        $q_out = gen_205();
    }
    else if ($type == 206)
    {
        $q_out = gen_206();
    }
    else if ($type == 207)
    {
        $q_out = gen_207();
    }
    else if ($type == 208)
    {
        $q_out = gen_208();
    }
    else if ($type == 209)
    {
        $q_out = gen_209();
    }
    else if ($type == 210)
    {
        $q_out = gen_210();
    }
    else if ($type == 211)
    {
        $q_out = gen_211();
    }
    else if ($type == 212)
    {
        $q_out = gen_212();
    }
    else if ($type == 213)
    {
        $q_out = gen_213();
    }
    else if ($type == 214)
    {
        $q_out = gen_214();
    }
    else if ($type == 215)
    {
        $q_out = gen_215();
    }
    else if ($type == 216)
    {
        $q_out = gen_216();
    }
    else if ($type == 217)
    {
        $q_out = gen_217();
    }
    else if ($type == 218)
    {
        $q_out = gen_218();
    }
    else if ($type == 219)
    {
        $q_out = gen_219();
    }
    else if ($type == 220)
    {
        $q_out = gen_220();
    }
    else if ($type == 221)
    {
        $q_out = gen_221();
    }
    else if ($type == 222)
    {
        $q_out = gen_222();
    }
    else if ($type == 223)
    {
        $q_out = gen_223();
    }
    else if ($type == 224)
    {
        $q_out = gen_224();
    }
    else if ($type == 225)
    {
        $q_out = gen_225();
    }
    else if ($type == 226)
    {
        $q_out = gen_226();
    }
    else if ($type == 227)
    {
        $q_out = gen_227();
    }
    else if ($type == 228)
    {
        $q_out = gen_228();
    }
    else if ($type == 229)
    {
        $q_out = gen_229();
    }
    else if ($type == 230)
    {
        $q_out = gen_230();
    }
    else if ($type == 231)
    {
        $q_out = gen_231();
    }
    else if ($type == 232)
    {
        $q_out = gen_232();
    }
    else if ($type == 233)
    {
        $q_out = gen_233();
    }
    else if ($type == 234)
    {
        $q_out = gen_234();
    }
    else if ($type == 235)
    {
        $q_out = gen_235();
    }
    else if ($type == 236)
    {
        $q_out = gen_236();
    }
    else if ($type == 237)
    {
        $q_out = gen_237();
    }
    else if ($type == 238)
    {
        $q_out = gen_238();
    }
    else if ($type == 239)
    {
        $q_out = gen_239();
    }
    else if ($type == 240)
    {
        $q_out = gen_240();
    }
    else if ($type == 241)
    {
        $q_out = gen_241();
    }
    else if ($type == 242)
    {
        $q_out = gen_242();
    }
    else if ($type == 243)
    {
        $q_out = gen_243();
    }
    else if ($type == 244)
    {
        $q_out = gen_244();
    }
    else if ($type == 245)
    {
        $q_out = gen_245();
    }
    else if ($type == 246)
    {
        $q_out = gen_246();
    }
    else if ($type == 247)
    {
        $q_out = gen_247();
    }
    else if ($type == 248)
    {
        $q_out = gen_248();
    }
    else if ($type == 249)
    {
        $q_out = gen_249();
    }
    else if ($type == 250)
    {
        $q_out = gen_250();
    }
    else if ($type == 251)
    {
        $q_out = gen_251();
    }
    else if ($type == 252)
    {
        $q_out = gen_252();
    }
    else if ($type == 253)
    {
        $q_out = gen_253();
    }
    else if ($type == 254)
    {
        $q_out = gen_254();
    }
    else if ($type == 255)
    {
        $q_out = gen_255();
    }
    else if ($type == 256)
    {
        $q_out = gen_256();
    }
    else if ($type == 257)
    {
        $q_out = gen_257();
    }
    else if ($type == 258)
    {
        $q_out = gen_258();
    }
    else if ($type == 259)
    {
        $q_out = gen_259();
    }
    else if ($type == 260)
    {
        $q_out = gen_260();
    }
    else if ($type == 261)
    {
        $q_out = gen_261();
    }
    else if ($type == 262)
    {
        $q_out = gen_262();
    }
    else if ($type == 263)
    {
        $q_out = gen_263();
    }
    else if ($type == 264)
    {
        $q_out = gen_264();
    }
    else if ($type == 265)
    {
        $q_out = gen_265();
    }
    else if ($type == 266)
    {
        $q_out = gen_266();
    }
    else if ($type == 267)
    {
        $q_out = gen_267();
    }
    else if ($type == 268)
    {
        $q_out = gen_268();
    }
    else if ($type == 269)
    {
        $q_out = gen_269();
    }
    else if ($type == 270)
    {
        $q_out = gen_270();
    }
    else if ($type == 271)
    {
        $q_out = gen_271();
    }
    else if ($type == 272)
    {
        $q_out = gen_272();
    }
    else if ($type == 273)
    {
        $q_out = gen_273();
    }
    else if ($type == 274)
    {
        $q_out = gen_274();
    }
    else if ($type == 275)
    {
        $q_out = gen_275();
    }
    else if ($type == 276)
    {
        $q_out = gen_276();
    }
    else if ($type == 277)
    {
        $q_out = gen_277();
    }
    else if ($type == 278)
    {
        $q_out = gen_278();
    }
    else if ($type == 279)
    {
        $q_out = gen_279();
    }
    else if ($type == 280)
    {
        $q_out = gen_280();
    }
    else if ($type == 281)
    {
        $q_out = gen_281();
    }
    else if ($type == 282)
    {
        $q_out = gen_282();
    }
    else if ($type == 283)
    {
        $q_out = gen_283();
    }
    else if ($type == 284)
    {
        $q_out = gen_284();
    }
    else if ($type == 285)
    {
        $q_out = gen_285();
    }
    else if ($type == 286)
    {
        $q_out = gen_286();
    }
    else if ($type == 287)
    {
        $q_out = gen_287();
    }
    else if ($type == 288)
    {
        $q_out = gen_288();
    }
    else if ($type == 289)
    {
        $q_out = gen_289();
    }
    else if ($type == 290)
    {
        $q_out = gen_290();
    }
    else if ($type == 291)
    {
        $q_out = gen_291();
    }
    else if ($type == 292)
    {
        $q_out = gen_292();
    }
    else if ($type == 293)
    {
        $q_out = gen_293();
    }
    else if ($type == 294)
    {
        $q_out = gen_294();
    }
    else if ($type == 295)
    {
        $q_out = gen_295();
    }
    else if ($type == 296)
    {
        $q_out = gen_296();
    }
    else if ($type == 297)
    {
        $q_out = gen_297();
    }
    else if ($type == 298)
    {
        $q_out = gen_298();
    }
    else if ($type == 299)
    {
        $q_out = gen_299();
    }
    else if ($type == 300)
    {
        $q_out = gen_300();
    }
    else if ($type == 301)
    {
        $q_out = gen_301();
    }
    else if ($type == 302)
    {
        $q_out = gen_302();
    }
    else if ($type == 303)
    {
        $q_out = gen_303();
    }
    else if ($type == 304)
    {
        $q_out = gen_304();
    }
    else if ($type == 305)
    {
        $q_out = gen_305();
    }
    else if ($type == 306)
    {
        $q_out = gen_306();
    }
    else if ($type == 307)
    {
        $q_out = gen_307();
    }
    else if ($type == 308)
    {
        $q_out = gen_308();
    }
    else if ($type == 309)
    {
        $q_out = gen_309();
    }
    else if ($type == 310)
    {
        $q_out = gen_310();
    }
    else if ($type == 311)
    {
        $q_out = gen_311();
    }
    else if ($type == 312)
    {
        $q_out = gen_312();
    }
    else if ($type == 313)
    {
        $q_out = gen_313();
    }
    else if ($type == 314)
    {
        $q_out = gen_314();
    }
    else if ($type == 315)
    {
        $q_out = gen_315();
    }
    else if ($type == 316)
    {
        $q_out = gen_316();
    }
    else if ($type == 317)
    {
        $q_out = gen_317();
    }
    else if ($type == 318)
    {
        $q_out = gen_318();
    }
    else if ($type == 319)
    {
        $q_out = gen_319();
    }
    else if ($type == 320)
    {
        $q_out = gen_320();
    }
    else if ($type == 321)
    {
        $q_out = gen_321();
    }
    else if ($type == 322)
    {
        $q_out = gen_322();
    }
    else if ($type == 323)
    {
        $q_out = gen_323();
    }
    else if ($type == 324)
    {
        $q_out = gen_324();
    }
    else if ($type == 325)
    {
        $q_out = gen_325();
    }
    else if ($type == 326)
    {
        $q_out = gen_326();
    }
    else if ($type == 327)
    {
        $q_out = gen_327();
    }
    else if ($type == 328)
    {
        $q_out = gen_328();
    }
    else if ($type == 329)
    {
        $q_out = gen_329();
    }
    else if ($type == 330)
    {
        $q_out = gen_330();
    }
    else if ($type == 330)
    {
        $q_out = gen_330();
    }
    else if ($type == 331)
    {
        $q_out = gen_331();
    }
    else if ($type == 332)
    {
        $q_out = gen_332();
    }
    else if ($type == 333)
    {
        $q_out = gen_333();
    }
    else if ($type == 334)
    {
        $q_out = gen_334();
    }
    else if ($type == 335)
    {
        $q_out = gen_335();
    }
    else if ($type == 336)
    {
        $q_out = gen_336();
    }
    else if ($type == 337)
    {
        $q_out = gen_337();
    }
    else if ($type == 338)
    {
        $q_out = gen_338();
    }
    else if ($type == 339)
    {
        $q_out = gen_339();
    }
    else if ($type == 340)
    {
        $q_out = gen_340();
    }
    else if ($type == 341)
    {
        $q_out = gen_341();
    }
    else if ($type == 342)
    {
        $q_out = gen_342();
    }
    else if ($type == 343)
    {
        $q_out = gen_343();
    }
    else if ($type == 344)
    {
        $q_out = gen_344();
    }
    else if ($type == 345)
    {
        $q_out = gen_345();
    }
    else if ($type == 346)
    {
        $q_out = gen_346();
    }
    else if ($type == 347)
    {
        $q_out = gen_347();
    }
    else if ($type == 348)
    {
        $q_out = gen_348();
    }
    else if ($type == 349)
    {
        $q_out = gen_349();
    }
    else if ($type == 350)
    {
        $q_out = gen_350();
    }else
    {
    	  echo $type;
        echo "<h3> *** WARNING  *** <br>";
        echo "GEN QUESTION WAS PASSED UNDEFINED TYPE NUMBER <br>";
        echo "NUMBER PASSED WAS ".$type."<br>";
        echo "RETURNING FALSE <br>";
        echo "PLEASE CONTACT WEBMASTER IMMEDIATLY <br>";
        echo "*** WARNING *** </h3>";
        return FALSE;
    }
    return $q_out;
}

function gen_directions($type)
{
    $directions = "";
    if ($type < 13)  /// old type 1-3
    {
        $directions = "Perform the indicated operation and reduce to lowest terms.";
    }
    else if ($type < 17)  /// old type 4
    {
        $directions = "Evaluate the given expression.";
    }
    else if ($type < 24) ///  old type 5
    {
        $directions = "Simplify: Write with positive exponents only. Assume all variables are greater than 0";
    }
    else if ($type < 28)
    {
        $directions = "Evaluate.";
    }
    else if ($type < 40)
    {
        $directions = "Simplify: Write with positive exponents only. Assume all variables are greater than 0";
    }
    else if ($type < 41)
    {
        $directions = "Simplify the given expressions.";
    }
    else if ($type < 52)
    {
        $directions = "Find the product.";
    }
    else if ($type < 76)
    {
        $directions = "Factor Completely.";
    }
    else if ($type < 89)
    {
        $directions = "Rational Expressions <br /> Perform the indicated operation and simplify.";
    }
    else if ($type < 103)
    {
        $directions = "Simplify.";
    }
    else if ($type < 110)
    {
        $directions = "Simplify each expression. Assume all variables are greater than 0.";
    }
    else if ($type < 114)
    {
        $directions = "Perform the indicated operation & simplify.";
    }
    else if ($type < 118)
    {
        $directions = "Rationalize the denominator.";
    }
    else if ($type < 135)
    {
        $directions = "Solve the following equation(s) for x.<br> <i> Be sure to reduce fractions </i>";
    }
    else if ($type < 140)
    {
        $directions = "Solve the following inequalitie(s) for x.<br> <i> Be sure to reduce fractions. </i>";
    }
    else if ($type < 156)
    {
        $directions = "Give Answer in form of a single expression or polynomial<br>";
        $directions .= "<i>For Polynomials leave the </i>Denominator<i> answer space blank.</i>";
    }
    else if ($type < 163)
    {
        $directions = "State the domain of the following function.";
    }
    else if ($type < 180)
    {
        $directions = "Find the equation of the line with the following properties:";
    }
    else if ($type < 186)
    {
        $directions = "Find the linear equation that models the following quasi-real-world situation:";
    }
    else if ($type < 189)
    {
        $directions = "Find the answer to the nearest cent. (<i>round up .0050</i>)";
    }
    else if ($type < 190)
    {
        $directions = "Find the larger tax.";
    }
    else if ($type < 191)
    {
        $directions = "Find the equation of the tax with the following properties;";
    }
    else if ($type < 194)
    {
        $directions = "Find the answer in decimal form.<br> Please round to the nearest third decimal place.";
        $directions .= "<br>(<i> If the fourth decimal place is 5 or greater round up </i>)";
    }
    else if ($type < 197)
    {
        $directions = "Find the answer in decimal form.<br> Please round to the nearest third decimal place.";
        $directions .= "<br>(<i> If the fourth decimal place is 5 or greater round up </i>)";
    }
    else if ($type < 199)
    {
        $directions = "Find the answer in scientific notation.<br> Please round the coefficient to the nearest hundreth.";
        $directions .= "<br>(<i> Round 0.005 up </i>)";
    }
    else if ($type < 201)
    {
        $directions = "Find the answer in decimal form.<br> Please round to the nearest third decimal place.";
        $directions .= "<br>(<i> If the fourth decimal place is 5 or greater round up </i>)";
    }
    else if ($type < 204)
    {
        $directions = "Find the answer in decimal form.<br> Please round to the nearest third decimal place.";
        $directions .= "<br>(<i> If the fourth decimal place is 5 or greater round up </i>)";
    }
    else if ($type < 205)
    {
        $directions = "Write in an equivalent form using logarithms:";
    }
    else if ($type < 206)
    {
        $directions = "Write in an equivalent form using exponents:";
    }
    else if ($type < 207)
    {
        $directions = "Find the answer in decimal form.<br> Please round to the nearest third decimal place.";
        $directions .= "<br>(<i> If the fourth decimal place is 5 or greater round up </i>)";
    }
    else if ($type < 208)
    {
        $directions = "Find the answer in decimal form.<br> Please round to the nearest third decimal place.";
        $directions .= "<br>(<i> If the fourth decimal place is 5 or greater round up </i>)";
    }
    else if ($type < 209)
    {
        $directions = "Identify the Growth Rate and Initial Population:";
    }
    else if ($type < 210)
    {
        $directions = "Identify the growth rate as a percentage:";
    }
    else if ($type < 211)
    {
        $directions = "Determine if the model grows or decays:";
    }
    else if ($type < 214)
    {
        $directions = "Find the equation that models the following situation:";
    }
    else if ($type < 217)
    {
        $directions = "Find the indicated value.";
        $directions .= "<br><font size=3>Please Round to the second decimal place (if necessary)<br>";
        $directions .= "<i>If the third decimal place is 5 or higher round up.</i><br>";
        $directions .= "<i>Remember to round DOWN to the nearest whole ";
        $directions .= "number if your answer refers to an animal or person.</i></font><br>";
    }
    else if ($type < 218)
    {
        $directions = "Find which job would pay more after 7 years:";
    }
    else if ($type < 219)
    {
        $directions = "Given the following table please identify if it represents<br>";
        $directions .= " a function that is linear or exponential in nature,<br> and if the equation ";
        $directions .= "grows or decays.";
    }
    else if ($type < 220)
    {
        $directions = "Find which job would pay more after 7 years:";
    }
    else if ($type < 222)
    {
        $directions = "Given the following table construct an equation for P(t) as an exponential function of t.";
    }
    else if ($type < 224)
    {
        $directions = "Find the equation that models the following situation<br>";
        $directions .= "<i>Please round the exponential to the fourth decimal place.</i>";
    }
    else if ($type < 228)
    {
        $directions = "Find the indicated value.";
    }
    else if ($type < 237)
    {
        $directions = "Use the properties of logarithms to write the expression";
        $directions .= "as a sum or difference of logarithms.";
    }
    else if ($type < 244)
    {
        $directions = "Use the laws of logarithms to rewrite the expression as a single logarithm.";
    }
    else if ($type < 253)
    {
        $directions = "Solve the following exponential equation.<br>";
        $directions .= "<br><font size=3>Please Round to the fourth decimal place (if necessary)<br>";
        $directions .= "<i>If the fifth decimal place is 5 or higher round up.</i>";
    }
    else if ($type < 264)
    {
        $directions = "Solve the logarithmic equation for x.";
    }
    else if ($type < 267)
    {
        $directions = "Find the Domain of the following equation.";
    }
    else if ($type < 268)
    {
        $directions = "Rewrite the following equations using base e.";
    }
    else if ($type < 269)
    {
        $directions = "Find the answer in decimal form.<br> Please round to the nearest second decimal place.";
        $directions .= "<br>(<i> If the third decimal place is 5 or greater round up </i>)";
    }
    else if ($type < 274)
    {
        $directions = "Find the indicated composition of functions";
    }
    else if ($type < 275)
    {
        $directions = "Find the power function that the graph of f resembles for large values of x if:";
    }
    else if ($type < 277)
    {
        $directions = "Find the description that best fits the following function for large values of x.";
    }
    else if ($type < 278)
    {
        $directions = "Pick which sentence best describes the behavior of the function at the given x value.";
    }
    else if ($type < 279)
    {
        $directions = "";
    }
    else if ($type < 280)
    {
        $directions = "Find the indicated value.";
    }
    else if ($type < 281)
    {
        $directions = "Find the indicated value.";
    }
    else if ($type < 283)
    {
        $directions = "Find the real zeros of the following quadratic function.";
    }
    else if ($type < 285)
    {
        $directions = "What value would you add and subtract from the following function when <br>";
        $directions .= "completing the square?";
    }
    else if ($type < 287)
    {
        $directions = "At what x-value does the following function have its vertex";
    }
    else if ($type < 289)
    {
        $directions = "Find the max/min value of the following function.<br>";
        $directions .= "Find the answer in decimal form.<br> Please round to the nearest second decimal place.";
        $directions .= "<br>(<i> If the third decimal place is 5 or greater round up </i>)";
    }
    else if ($type < 290)
    {
        $directions = "Put the following quadractic function in standard form.";
    }
    else if ($type < 292)
    {
        $directions = "The graph of the following function is the graph of f ( x ) = x<sup> 2</sup> translated:";
        $directions .= "<br>( <i>Please check all that apply. </i>)";
    }
    else if ($type < 296)
    {
        $directions = "Answer the following word problems";
    }
    else if ($type < 308)
    {
        $directions = "Solve the following inequalities.";
    }
    else if ($type < 309)
    {
        $directions = "Find the power function that the graph of P resembles for large values of x if:";
    }
    else if ($type < 310)
    {
        $directions = "Find the description that best fits the following function for large values of x.";
    }
    else if ($type < 311)
    {
        $directions = "According to the Rational Zero Theorem, the complete set of <u>";
        $directions .= "possible</u> rational zeros of the follwing polynomial is:";
    }
    else if ($type < 314)
    {
        $directions = "Use synthetic division to divide the following two factors. Find the Quotient and remainder.";
    }
    else if ($type < 316)
    {
        $directions = "Use synthetic division to evaluate the following polynomial at the specified point.";
    }
    else if ($type < 317)
    {
        $directions = "Find the complete set of real zeros for the following polynomail.";
    }
    else if ($type < 319)
    {
        $directions = "Find the complete set of real zeros for the following polynomail.";
        $directions .= "<br> (<i> Please seperate the different zeros by commas</i>)";
    }
    else if ($type < 320)
    {
        $directions = "A third degree polynomial with the following zeros would be:";
    }
    else if ($type < 323)
    {
        $directions = "Find the indicated value.";
    }
    else if ($type < 328)
    {
        $directions = "Use the formula h = -16 t<sup> 2</sup> + <i>v</i><sub>0</sub> t<br> and to ";
        $directions .= "answer the following question(s).";
    }
    else if ($type < 329)
    {
        $directions = "Given <i>I</i><sub>0</sub> = 10<sup> -16</sup> watts/cm<sup> 2</sup>.<br>";
        $directions .= "Find the indicated value";
    }
    else if ($type < 330)
    {
        $directions = "Find the indicated value.";
    }
    else if ($type < 351)
    {
        $directions = "Factor Completely. Leave no negative exponents.";
    }
    else
    {
        echo "gen_directions passed a non-question-type<br>";
        echo "type passed was $i";
        return FALSE;
    }
    return $directions;
}

function gen_q_out($i, $q_out)
{
    if ($i == 0)
    {
        return "Error in Test Setup...Please Contact Your Teacher ASAP!";
    }
    else if ($i == 1)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 2)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 3)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 4)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 5)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 6)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 7)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 8)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 9)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 10)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 11)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 12)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 13)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 14)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 15)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 16)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 17)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 18)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 19)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 20)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 21)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 22)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 23)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 24)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 25)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 26)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 27)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 28)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 29)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 30)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 31)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 32)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 33)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 34)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 35)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 36)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 37)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }

    else if ($i == 38)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 39)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 40)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 41)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 42)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 43)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 44)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 45)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 46)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 47)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 48)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 49)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 50)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 51)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 52)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 53)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 54)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 55)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 56)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 57)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 58)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 59)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 60)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 61)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 62)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 63)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 64)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 65)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 66)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 67)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 68)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 69)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 70)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 71)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 72)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 73)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 74)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 75)
    {
        return simple_out($q_out[0]);
    }
    else if ($i == 76)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 77)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 78)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 79)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 80)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 81)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 82)
    {
        return simple_out($q_out[0],$q_out[1],30);
    }
    else if ($i == 83)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 84)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 85)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 86)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 87)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 88)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 89)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 90)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 91)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 92)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 93)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 94)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 95)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 96)
    {
        return "<br /><center>$q_out[0]<br /></center>\n";
    }
    else if ($i == 97)
    {
        return simple_out($q_out[0],$q_out[1], 30);
    }
    else if ($i == 98)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 99)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 100)
    {
        return simple_out($q_out[0],$q_out[1],33);
    }
    else if ($i == 101)
    {
        return simple_out($q_out[0],$q_out[1],33);
    }
    else if ($i == 102)
    {
        return simple_out($q_out[0],$q_out[1],33);
    }
    else if ($i == 103)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 104)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 105)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 106)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 107)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 108)
    {
        return simple_out($q_out[0],$q_out[1],27);
    }
    else if ($i == 109)
    {
        return simple_out($q_out[0],$q_out[1],27);
    }
    else if ($i == 110)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 111)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 112)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 113)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 114)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 115)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 116)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 117)
    {
        return simple_out($q_out[0],$q_out[1],23);
    }
    else if ($i == 118)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 119)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 120)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 121)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 122)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 123)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 124)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 125)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 126)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 127)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 128)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 129)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 130)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 131)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 132)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 133)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 134)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 135)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 136)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 137)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 138)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 139)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 140)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 141)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 142)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 143)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 144)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 145)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 146)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 147)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 148)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 149)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 150)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 151)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 152)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 153)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 154)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 155)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 156)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 157)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 158)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 159)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 160)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 161)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 162)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 163)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 164)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 165)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 166)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 167)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 168)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 169)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 170)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 171)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 172)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 173)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 174)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 175)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 176)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 177)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 178)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 179)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 180)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 181)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 182)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 183)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 184)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 185)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 186)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 187)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 188)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 189)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 190)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 191)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 192)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 193)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 194)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 195)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 196)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 197)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 198)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 199)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 200)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 201)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 202)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 203)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 204)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 205)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 206)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 207)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 208)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 209)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 210)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 211)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 212)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 213)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 214)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 215)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 216)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 217)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 218)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 219)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 218)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 219)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 220)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 221)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 222)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 223)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 224)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 225)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 226)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 227)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 228)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 229)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 230)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 231)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 232)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 233)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 234)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 235)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 236)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 237)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 238)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 239)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 240)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 241)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 242)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 243)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 244)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 245)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 246)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 247)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 248)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 249)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 250)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 251)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 252)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 253)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 254)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 255)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 256)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 257)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 258)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 259)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 260)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 261)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 262)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 263)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 264)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 265)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 266)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 267)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 268)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 269)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 270)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 271)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 272)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 273)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 274)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 275)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 276)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 277)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 278)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 279)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 280)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 281)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 282)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 283)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 284)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 285)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 286)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 287)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 288)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 289)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 290)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 291)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 292)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 293)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 294)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 295)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 296)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 297)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 298)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 299)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 300)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 301)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 302)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 303)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 304)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 305)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 306)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 307)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 308)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 309)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 310)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 311)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 312)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 313)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 314)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 315)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 316)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 317)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 318)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 319)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 320)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 321)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 322)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 323)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 324)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 325)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 326)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 327)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 328)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 329)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 330)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 331)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 332)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 333)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 334)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 335)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 336)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 337)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 338)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 339)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 340)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 341)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 342)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 343)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 344)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 345)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 346)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 347)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 348)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 349)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else if ($i == 350)
    {
        return "<br /><center>$q_out[0]</center><br />";
    }
    else
    {
        return "gen_q_out was passed a non-question type int: '$i'";
    }
}

function gen_a_out($numerator, $denominator, $number)
{
    ////  up to date as of question type #350
    $line_length = array(10, 10, 10, 10, 10, 12, 12, 12, 12, 15, 15, 15, 15,
                         15, 15, 15, 15, 15, 15, 15, 19, 19, 19, 15, 15, 15,
                         10, 15, 18, 15, 15, 15, 15, 15, 15, 15, 15, 13, 13,
                         15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                         15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                         15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 20, 23, 23,
                         23, 23, 15, 15, 15, 28, 25, 25, 33, 28, 19, 15, 15,
                         25, 15, 19, 19, 19, 19, 15, 18, 18, 15, 15, 15, 15,
                         15, 15, 15, 15, 22, 22, 15, 15, 15, 15, 15, 15, 22,
                         22, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12,  0,  0,  0,  0,  0, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                         12, 12, 12, 12, 25, 12, 25, 27, 12, 27, 12, 40, 60,
                         12, 12, 12, 12, 12, 12, 12, 12, 12, 20, 20, 25);

    return simple_out($numerator, $denominator, $line_length[$number - 1]);
}

function gen_answer_input($type,$num,$x_var = 0, $y_var = 0, $a_array = NULL)
{
    if ($type < 117)
    {
        return answer_input($num, $a_array);
    }
    else if ($type < 135)
    {
       return equation_answer_input($num, $a_array);
    }
    else if ($type < 139)
    {
        return simple_interval_answer_input($num, $a_array);
    }
    else if ($type < 140)
    {
        return interval_answer_input($num, $a_array);
    }
    else if ($type < 156)
    {
       return  answer_input($num, $a_array);
    }
    else if ($type < 158)
    {
       return  domain_answer_input($num, $a_array);
    }
    else if ($type <159)
    {
       return  domain_answer_input1($num, $a_array);
    }else if ($type <162)
    {
       return  domain_answer_input($num, $a_array);
    }
    else if ($type <163)
    {
       return  domain_answer_input1($num, $a_array);
    }
    else if ($type < 180)
    {
        return linear_equation_answer_input($num, $a_array);
    }
    else if ($type < 186)
    {
        return linear_equation_reform_answer_input($num,$x_var,$y_var, $a_array);
    }
    else if ($type < 189)
    {
        return  answer_input($num, $a_array);
    }
    else if ($type < 190)
    {
        return compare_tax_answer_input($num, $a_array);
    }
    else if ($type < 191)
    {
        return tax_equation_answer_input($num, $a_array);
    }
    else if ($type < 197)
    {
        return  answer_input($num, $a_array);
    }
    else if ($type < 199)
    {
        return sci_answer_input($num, $a_array);
    }
    else if ($type < 204)
    {
       return  answer_input($num, $a_array);
    }
    else if ($type < 205)
    {
         return common_log_form_answer_input($num, $a_array);
    }
    else if ($type < 206)
    {
         return easy_exp_form_answer_input($num, $a_array);
    }
    else if ($type < 208)
    {
         return  answer_input($num, $a_array);
    }
    else if ($type < 209)
    {
         return initial_pop_growth_rate_answer_input($num, $a_array);
    }
    else if ($type < 210)
    {
         return simple_answer_percentage_input($num, $a_array);
    }
    else if ($type < 211)
    {
         return growth_vs_decay_answer_input($num, $a_array);
    }
    else if ($type < 214)
    {
         return exponential_equation_answer_input($num, $a_array);
    }
    else if ($type < 217)
    {
          return  answer_input($num, $a_array);
    }
    else if ($type < 218)
    {
         return compare_salary_answer_input($num, $a_array);
    }
    else if ($type < 219)
    {
         return growth_type_answer_input($num, $a_array);
    }
    else if ($type < 220)
    {
         return compare_salary_answer_input($num, $a_array);
    }
    else if ($type < 224)
    {
         return exponential_equation_answer_input($num, $a_array);
    }
//    else if ($type < 224)
//    {
//         return exponential_equation_2_answer_input($num, $a_array);
//    }
    else if ($type < 226)
    {
         return simple_answer_money_input($num, $a_array);
    }
    else if ($type < 227)
    {
        return simple_answer_t_input($num, $a_array);
    }
    else if ($type < 228)
    {
       return  simple_answer_percentage_input($num, $a_array);
    }
    else if ($type < 244)
    {
        return  answer_input($num, $a_array);
    }
    else if ($type < 256)
    {
       return equation_answer_input($num, $a_array);
    }
    else if ($type < 264)
    {
        return quadratic_equation_answer_input($num, $a_array);
    }
    else if ($type < 267)
    {
        return domain_answer_input($num, $a_array);
    }
    else if ($type < 268)
    {
        return exponential_equation_3_answer_input($num, $a_array);
    }
    else if ($type < 269)
    {
        return simple_answer_t_input($num, $a_array);
    }
    else if ($type < 274)
    {
        return  answer_input($num, $a_array);
    }
    else if ($type < 275)
    {
        return end_behavior_1_answer_input($num, $a_array);
    }
    else if ($type < 277)
    {
        return end_behavior_2_answer_input($num, $a_array);
    }
    else if ($type < 278)
    {
        return zero_behavior_answer_input($num, $a_array);
    }
    else if ($type < 279)
    {
        return proportion_1_answer_input($num, $a_array);
    }
    else if ($type < 281)
    {
        return proportion_2_answer_input($num, $a_array);
    }
    else if ($type < 282)
    {
        return quadratic_equation_answer_input($num, $a_array);
    }
    else if ($type < 283)
    {
        return quadratic_equation_2_answer_input($num, $a_array);
    }
    else if ($type < 285)
    {
        return answer_input($num, $a_array);
    }
    else if ($type < 287)
    {
        return equation_answer_input($num, $a_array);
    }
    else if ($type < 289)
    {
        return  answer_input($num, $a_array);
    }
    else if ($type < 290)
    {
        return standard_form_answer_input($num, $a_array);
    }
    else if ($type < 292)
    {
        return translation_answer_input($num, $a_array);
    }
    else if ($type < 294)
    {
        return answer_input($num, $a_array);
    }
    else if ($type < 296)
    {
        return length_width_answer_input($num, $a_array);
    }
    else if ($type < 308)
    {
        return interval_answer_input($num, $a_array);
    }
    else if ($type < 309)
    {
        return end_behavior_3_answer_input($num, $a_array);
    }
    else if ($type < 310)
    {
        return end_behavior_4_answer_input($num, $a_array);
    }
    else if ($type < 314)
    {
        return multiple_choice_answer_input($num, $a_array);
    }
    else if ($type < 316)
    {
        return answer_input($num, $a_array);
    }
    else if ($type < 317)
    {
        return multiple_choice_answer_input($num, $a_array);
    }
    else if ($type < 319)
    {
        return simple_answer_input($num, $a_array);
    }
    else if ($type < 320)
    {
        return multiple_choice_answer_input($num, $a_array);
    }
    else if ($type < 322)
    {
        return simple_answer_money_input($num, $a_array);
    }
    else if ($type < 323)
    {
        return simple_answer_t_input($num, $a_array);
    }
    else if ($type < 327)
    {
        return projectile_2_answer_input($num, $a_array);
    }
    else if ($type < 328)
    {
        return projectile_1_answer_input($num, $a_array);
    }
    else if ($type < 330)
    {
        return simple_answer_input($num, $a_array);
    }
    else if ($question_type < 351)
    {
        return answer_input($num, $a_array);
    }
    else
    {
        echo "gen_answer_input() was passed non-question-type<br>\n";
        echo "type was $type on number $num.<br>\n";
        return FALSE;
    }
}

function gen_inequality($i)
{
    $temp_string = "";
    if ($i == 1)
    {
        $temp_string = "<";
    }
    else if ($i == 2)
    {
        $temp_string = "<=";
    }
    else if ($i == 3)
    {
        $temp_string = ">";
    }
    else // $i == 4
    {
        $temp_string = ">=";
    }
    return $temp_string;
}

function gen_parser_out($question_array,$q_type)
{
    $my_string = "";

    $num   = $question_array[1];
    $denom = $question_array[2];
    $x_var = $question_array[3];
    $y_var = $question_array[4];
    $type  = $question_array[5];

    if ($type == 1)
    {
        $my_string = parse_inequality_output($num);
    }
    else if ($type == 3)
    {
        $my_string = parse_tax_equation_answer_output($num);
    }
    else if ($type == 4)
    {
        $my_string = parse_sci_answer_output($num,$denom);
    }
    else if ($type == 5)
    {
        $my_string = parse_common_log_form_answer_output($num,$denom);
    }
    else if ($type == 6)
    {
        $my_string = parse_easy_exp_form_answer_output($num,$denom);
    }
    else if ($type == 7)
    {
        $my_string = parse_initial_pop_form_answer_output($num,$denom);
    }
    else if ($type == 8)
    {
        $my_string = parse_growth_rate_percent_form_answer_output($num);
    }
    else if ($type == 9)
    {
        $my_string = parse_growth_vs_decay_answer($num);
    }
    else if ($type == 10)
    {
        $my_string = parse_exp_equation_answer($num, $denom);
    }
    else if ($type == 11)
    {
        $my_string = parse_compare_salary_answer($num);
    }
    else if ($type == 12)
    {
        $my_string = parse_growth_type_answer($num);
    }
    else if ($type == 13)
    {
        $my_string = parse_exp_equation_2_answer($num, $denom);
    }
    else if ($type == 14)
    {
        $my_string = parse_expand_the_log_output($num, $denom);
    }
    else if ($type == 15)
    {
        $my_string = parse_write_a_single_log_output($num, $denom);
    }
    else if ($type == 16)
    {
        $my_string = parse_quadratic_output($num);
    }
    else if ($type == 17)
    {
        $my_string = parse_exp_equation_3_answer($num, $denom);
    }
    else if ($type == 18)
    {
        $my_string = parse_end_behavior_1_answer($num);
    }
    else if ($type == 19)
    {
        $my_string = parse_end_behavior_2_answer($num);
    }
    else if ($type == 20)
    {
        $my_string = parse_proportion_1_answer($num);
    }
    else if ($type == 21)
    {
        $my_string = parse_proportion_2_answer($num,$denom);
    }
    else if ($type == 22)
    {
        $my_string = parse_zero_behavior_answer($num);
    }
    else if ($type == 23)
    {
        $my_string = parse_quadratic_2_output($num);
    }
    else if ($type == 24)
    {
        $my_string = parse_standard_form_output($num);
    }
    else if ($type == 25)
    {
        $my_string = parse_translation_output($num);
    }
    else if ($type == 26)
    {
        $my_string = parse_length_width_output($num);
    }
    else if ($type == 27)
    {
        $my_string = parse_end_behavior_3_answer($num,$denom);
    }
    else if ($type == 28)
    {
        $my_string = parse_end_behavior_4_answer($num);
    }
    else if ($type == 29)
    {
        $my_string = parse_multiple_choice_output($num);
    }
    else if ($type == 30)
    {
        $my_string = parse_projectile_2_output($num);
    }
    else if ($type == 31)
    {
        $my_string = parse_domain_answer_output($num,$denom);
    }
    else if ($type == 32)
    {
        $my_string = parse_linear_equation_answer($num);
    }
    else if ($type == 33)
    {
        $my_string = parse_linear_equation_reform_answer($num,$x_var,$y_var);
    }
    else
    {
        $num = str_to_math($num);
        $denom = str_to_math($denom);
        $my_string = gen_a_out($num,$denom, $q_type);
    }
    return $my_string;
}

function gen_correct_answer_form($answer_type,$ai_array)
{
    $debug = FALSE;
    $num   = "";
    $denom = "";

    if ($answer_type == 1)
    {
        $num = parse_interval_answer($ai_array);
        if (!strlen($num))
        {
            $denom = "";
        }
        else
        {
            $denom = 1;
        }
    }
    else if ($answer_type == 2)
    {
        $num = parse_compare_tax_answer($ai_array);
        if (!strlen($num))
        {
            $denom = "";
        }
        else
        {
            $denom = 1;
        }
    }
    else if ($answer_type == 3)
    {
        $num = parse_tax_equation_answer($ai_array);
        if (!strlen($num))
        {
            $denom = "";
        }
        else
        {
            $denom = "1";
        }
    }
    else if ($answer_type == 14)
    {
        $num = parse_expand_the_log_input($ai_array);
        if (!strlen($num))
        {
            $denom = "";
        }
        else
        {
            $denom = "1";
        }
    }
    else if ($answer_type == 15)
    {
        $num = parse_write_single_log_input($ai_array);
        if (!strlen($num))
        {
            $denom = "";
        }
        else
        {
            $denom = "1";
        }
    }
    else if ($answer_type == 16 || $answer_type == 23 || $answer_type == 26)
    {
        $num = parse_quadratic_input($ai_array);
        if (!strlen($num))
        {
            $denom = "";
        }
        else
        {
            $denom = "1";
        }
    }
    else if ($answer_type == 21)
    {
        $num = $ai_array[0];
        $denom = $ai_array[1];
        if (!(strlen($denom)))
        {
            $num = "";
        }
    }
    else if ($answer_type == 24)
    {
        $num = parse_standard_form_input($ai_array);
        if (!(strlen($num)))
        {
            $denom = "";
        }
        else
        {
            $denom = 1;
        }
    }
    else if ($answer_type == 25)
    {
        $num = parse_translation_input($ai_array);
        if (!(strlen($num)))
        {
            $denom = "";
        }
        else
        {
            $denom = 1;
        }
    }
    else if ($answer_type == 30)
    {
        $num = parse_projectile_2_input($ai_array);
        if (!strlen($num))
        {
            $denom = "";
        }
        else
        {
            $denom = "1";
        }
    }
    else if ($answer_type == 31 )
    {
        $denom = $ai_array[6];
        $num = parse_domain_answer($ai_array);
        if (strlen($denom) && !(strlen($num)))
        {
            $num = "(-inf,inf)";
        }
        if (!strlen($denom) && (strlen($num)))
        {
            $denom = "not_used";
        }
    }
    else if ($answer_type == 32 || $answer_type == 33)
    {
        $num = parse_linear_equation_answer_input($ai_array);
        if (!strlen($num))
        {
            $denom = "";
        }
        else
        {
            $denom = "1";
        }
    }
    else
    {
        $num   = $ai_array[0];
        $denom = $ai_array[1];
        if (!strlen($num) && strlen($denom))
        {
            $num = 1;
        }
        if (!strlen($denom) && strlen($num))
        {
            $denom = 1;
        }
    }
    if ($debug)
    {
        echo "<br> NUM: ";
        echo $num ;
        echo "<br> DENOM ";
        echo $denom;
        echo "<br>";
    }

    $result_array = array($num,$denom);

    return $result_array;
}

?>