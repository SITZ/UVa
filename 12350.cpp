#include <bits/stdc++.h>

using namespace std;

int sg[26][1850];
int per[] = {0, 1, 3, 3, 6, 12, 24, 12, 24, 24, 24, 24, 48, 48, 96, 96, 96, 192, 192, 384, 384, 384, 768, 768, 768, 768};
int g1[] = {1};
int g2[] = {-2, 2, 3};
int g3[] = {1, 5, 3};
int g4[] = {-1, 7, 3, 8, 10, 6};
int g5[] = {-1, -2, 3, 2, -3, 6, 5, 4, 1, 8, 7, 12};
int g6[] = {2, -2, 3, -5, 1, 6, 8, 4, 9, 11, 7, 12, 5, 10, 15, 17, 13, 18, 20, 16, 21, 23, 14, 24};
int g7[] = {-11, -10, 3, 4, 5, 6, 7, -4, -3, 10, 11, 12};
int g8[] = {1, -6, -10, 4, -3, -7, 7, 8, 9, 10, -4, 3, 12, 6, 15, 2, 11, 5, 16, 19, 13, 22, 23, 24};
int g9[] = {11, 12, 13, 3, -1, 7, 8, 18, 9, 10, 20, 21, 14, 22, 25, 15, 26, 19, 28, 29, 30, 17, 16, 24};
int g10[] = {8, -1, 13, 4, 14, 15, 12, 5, 9, 7, 10, 21, 11, 22, 25, 16, 26, 27, 17, 18, 30, 19, 20, 24};
int g11[] = {-8, 1, -15, -10, -12, 7, 8, 6, -3, 10, 11, -1, 13, 3, 17, 2, 18, 19, 5, 20, 22, 4, 15, 24};
int g12[] = {-4, -1, -9, 3, -6, 4, 8, -3, -11, 10, 1, 2, 9, -2, 5, 14, 6, 16, 19, 20, 17, 7, 11, 12, 25, 23, 15, 27, 18, 28, 32, 21, 13, 24, 35, 26, 33, 22, 29, 38, 30, 40, 43, 34, 41, 31, 36, 48};
int g13[] = {-21, 1, -9, -8, -11, -6, 5, 8, 7, -1, 10, 11, 12, 13, 2, 14, 6, -4, -2, 9, 17, 20, 21, 23, 3, 25, 15, 4, 28, 16, 29, 32, 31, 33, 24, 18, 34, 36, 26, 38, 19, 30, 22, 43, 41, 35, 45, 48};
int g14[] = {-19, -11, -9, -2, -20, 5, -12, -4, 3, -10, 10, 11, 6, 1, 2, 14, 16, 17, 18, 7, 20, 8, -1, 23, 24, 13, 15, 22, 4, 12, 31, 30, 27, 9, 19, 34, 35, 25, 26, 38, 40, 41, 42, 43, 32, 21, 33, 48, 29, 37, 39, 46, 28, 53, 36, 44, 51, 57, 45, 59, 54, 49, 50, 62, 64, 65, 66, 55, 68, 56, 47, 71, 58, 61, 63, 70, 52, 60, 79, 78, 75, 81, 67, 82, 83, 73, 74, 72, 88, 89, 90, 91, 80, 69, 93, 96};
int g15[] = {24, 26, 9, 27, 20, 13, 14, 19, 32, 34, 36, 37, 38, 23, 15, 28, 25, 29, 41, 30, 31, 35, 46, 49, 43, 50, 33, 51, 44, 54, 40, 45, 56, 58, 39, 47, 55, 48, 64, 52, 66, 42, 65, 69, 70, 68, 60, 74, 72, 75, 57, 59, 76, 61, 53, 67, 80, 83, 63, 85, 86, 62, 71, 88, 73, 77, 89, 78, 79, 82, 84, 97, 91, 98, 81, 99, 92, 102, 90, 93, 104, 107, 87, 94, 103, 95, 112, 100, 114, 101, 113, 117, 118, 106, 108, 96};
int g16[] = {-11, 17, 18, 1, 16, 6, 7, 21, 19, 25, 12, 28, 10, 14, 8, 30, 32, 20, 22, 15, 36, 24, 37, 40, 41, 42, 26, 43, 29, 23, 27, 47, 48, 33, 35, 50, 51, 52, 39, 55, 31, 57, 46, 44, 34, 45, 60, 65, 38, 64, 66, 67, 53, 54, 70, 69, 71, 74, 59, 76, 49, 61, 56, 79, 80, 68, 82, 63, 84, 58, 73, 72, 88, 62, 86, 90, 77, 93, 75, 95, 91, 81, 78, 98, 99, 100, 87, 101, 105, 89, 94, 92, 109, 107, 83, 96};
int g17[] = {17, 20, -8, 21, 22, 3, 10, 25, 26, 28, 11, 15, 29, 30, 4, 6, 35, 36, 37, 18, 39, 23, 27, 24, 44, 45, 16, 32, 42, 19, 33, 50, 34, 51, 38, 53, 54, 55, 57, 56, 31, 60, 41, 62, 61, 63, 64, 48, 47, 68, 40, 70, 66, 43, 49, 46, 58, 77, 59, 79, 80, 76, 52, 65, 83, 84, 69, 85, 73, 71, 86, 72, 89, 75, 91, 93, 90, 67, 81, 98, 78, 82, 99, 87, 74, 103, 105, 104, 94, 108, 92, 110, 109, 95, 111, 96, 113, 101, 88, 117, 116, 119, 97, 121, 106, 124, 107, 127, 122, 126, 100, 102, 131, 132, 133, 114, 135, 136, 123, 120, 140, 125, 112, 118, 138, 115, 129, 146, 130, 147, 134, 128, 150, 151, 153, 152, 142, 141, 137, 158, 157, 159, 160, 144, 143, 149, 148, 166, 156, 139, 145, 169, 154, 173, 155, 175, 176, 172, 177, 161, 179, 164, 165, 162, 183, 167, 182, 168, 185, 171, 187, 189, 186, 163, 193, 194, 174, 178, 181, 197, 170, 199, 201, 200, 190, 204, 188, 206, 205, 180, 191, 192};
int g18[] = {1, -19, 3, -18, -14, -9, 6, 8, -20, -10, -5, -4, 13, -7, 14, 15, 18, 2, 20, 21, 22, 19, 10, 7, 24, 5, 11, -1, 4, 29, 9, 33, 27, 12, 16, 36, 37, 17, 40, 41, 25, 26, 43, 45, 46, 23, 47, 31, 32, 30, 35, 49, 34, 39, 55, 56, 51, 28, 38, 42, 44, 61, 62, 48, 66, 50, 67, 68, 69, 70, 71, 72, 73, 53, 59, 54, 52, 63, 57, 81, 79, 82, 65, 83, 84, 86, 88, 58, 60, 74, 75, 93, 64, 90, 94, 77, 96, 78, 80, 98, 85, 87, 102, 104, 76, 107, 91, 92, 110, 89, 111, 112, 97, 115, 99, 114, 118, 116, 101, 103, 120, 121, 122, 95, 123, 125, 105, 129, 100, 108, 113, 131, 133, 134, 136, 106, 117, 109, 138, 141, 142, 119, 143, 127, 128, 126, 145, 132, 130, 135, 151, 152, 124, 156, 153, 140, 155, 137, 158, 144, 162, 163, 164, 165, 166, 146, 167, 168, 139, 149, 170, 150, 148, 159, 176, 177, 175, 147, 161, 180, 181, 179, 184, 154, 169, 157, 171, 189, 160, 186, 190, 192};
int g19[] = {6, 7, 23, 10, 11, 27, 29, 31, 5, 33, 14, 35, 30, 32, 17, 18, 19, 39, 40, 25, 24, 42, 44, 47, 49, 50, 28, 34, 51, 38, 22, 37, 36, 26, 55, 59, 60, 43, 41, 46, 64, 65, 66, 68, 48, 54, 67, 72, 52, 57, 73, 58, 45, 75, 78, 61, 79, 63, 80, 84, 81, 53, 85, 86, 71, 56, 76, 91, 92, 62, 94, 95, 96, 97, 98, 82, 69, 83, 70, 87, 77, 74, 90, 106, 88, 105, 89, 109, 112, 111, 113, 116, 117, 115, 93, 103, 100, 120, 119, 122, 104, 102, 125, 107, 127, 130, 108, 99, 129, 101, 114, 118, 136, 135, 138, 137, 141, 110, 128, 143, 145, 121, 124, 126, 146, 131, 149, 133, 132, 152, 151, 123, 156, 139, 140, 142, 159, 160, 144, 164, 165, 150, 134, 147, 148, 168, 153, 171, 169, 155, 174, 157, 175, 179, 154, 163, 181, 178, 161, 182, 167, 183, 172, 184, 173, 158, 188, 191, 176, 177, 162, 194, 193, 196, 166, 200, 180, 170, 186, 187, 204, 205, 185, 190, 208, 207, 209, 212, 213, 195, 189, 192, 198, 199, 201, 202, 203, 219, 221, 223, 197, 225, 206, 227, 222, 224, 210, 214, 211, 215, 232, 217, 216, 234, 236, 239, 241, 242, 220, 226, 243, 230, 245, 229, 228, 218, 247, 231, 252, 235, 233, 238, 256, 257, 258, 260, 240, 246, 259, 264, 244, 249, 265, 250, 237, 251, 270, 253, 271, 255, 272, 276, 273, 274, 277, 278, 263, 248, 268, 283, 284, 254, 286, 287, 288, 289, 290, 291, 261, 275, 262, 279, 269, 266, 282, 267, 280, 297, 281, 301, 304, 303, 305, 308, 309, 307, 285, 295, 292, 312, 311, 298, 296, 294, 317, 299, 319, 322, 300, 324, 321, 293, 306, 310, 328, 327, 330, 329, 333, 302, 320, 335, 337, 313, 316, 318, 338, 323, 341, 325, 344, 345, 314, 315, 348, 331, 332, 334, 351, 352, 336, 356, 357, 342, 326, 339, 340, 343, 361, 360, 362, 347, 366, 349, 367, 371, 346, 355, 373, 370, 353, 374, 359, 375, 364, 376, 365, 350, 380, 383, 368, 369, 354, 386, 385, 388, 358, 392, 372, 393, 378, 363, 396, 397, 377, 382, 400, 399, 379, 404, 405, 387, 381, 384};
int g20[] = {-16, 2, -3, 1, 4, 5, -27, 9, -9, 11, 12, -21, -11, -7, -2, -17, 18, 19, 20, -4, 6, 21, 22, -8, 8, 24, 7, 27, 29, 14, 30, 16, 32, 15, 13, 3, 10, 17, 40, 39, 42, 26, 41, 46, 28, 43, 23, 25, 33, 50, 45, 31, 51, 36, 37, 54, 55, 38, 56, 35, 60, 59, 63, 64, 47, 66, 34, 65, 49, 48, 52, 73, 57, 72, 76, 77, 44, 78, 61, 81, 79, 82, 83, 84, 58, 53, 62, 67, 68, 90, 69, 94, 95, 91, 71, 96, 97, 80, 74, 100, 98, 70, 85, 104, 102, 86, 106, 75, 108, 89, 92, 110, 114, 115, 113, 116, 119, 120, 118, 87, 88, 123, 103, 124, 107, 101, 93, 112, 122, 111, 109, 99, 134, 135, 136, 137, 138, 121, 105, 125, 140, 126, 143, 127, 128, 146, 141, 145, 131, 117, 133, 152, 151, 157, 153, 158, 156, 159, 139, 160, 162, 129, 130, 132, 166, 144, 148, 150, 169, 168, 170, 172, 154, 142, 176, 178, 179, 177, 180, 147, 182, 149, 163, 183, 164, 186, 155, 173, 191, 174, 167, 192, 193, 161, 189, 195, 196, 197, 165, 201, 198, 203, 204, 171, 181, 185, 190, 175, 187, 208, 194, 188, 214, 213, 215, 184, 200, 216, 199, 219, 221, 206, 223, 225, 222, 207, 205, 209, 202, 226, 211, 231, 232, 218, 212, 238, 220, 234, 239, 217, 224, 242, 210, 241, 233, 244, 229, 246, 247, 230, 248, 227, 252, 237, 255, 235, 258, 256, 236, 228, 262, 240, 261, 265, 249, 264, 268, 269, 251, 270, 253, 273, 271, 274, 275, 243, 250, 245, 254, 259, 260, 282, 281, 286, 287, 283, 263, 288, 257, 272, 266, 291, 290, 276, 277, 296, 294, 278, 298, 267, 300, 297, 284, 302, 306, 289, 305, 308, 311, 312, 310, 279, 280, 315, 295, 292, 299, 293, 285, 304, 314, 301, 320, 307, 303, 326, 328, 327, 329, 313, 330, 317, 316, 318, 332, 319, 321, 337, 322, 340, 323, 309, 325, 344, 338, 349, 345, 350, 343, 333, 331, 352, 335, 353, 354, 324, 358, 336, 356, 342, 361, 360, 362, 364, 346, 334, 348, 370, 351, 369, 339, 372, 371, 341, 355, 374, 378, 379, 347, 365, 383, 366, 359, 384};
int g21[] = {-3, 19, 1, 20, 18, 4, -10, 26, 24, -8, 29, 8, 30, 31, 13, -2, 16, 36, 17, 34, 38, 6, 39, 23, 21, 44, 9, 41, 25, 28, 27, 49, 46, 50, 51, 32, 33, 53, 37, 22, 35, 40, 60, 42, 43, 62, 63, 48, 64, 67, 47, 65, 57, 69, 45, 52, 73, 55, 74, 54, 71, 78, 59, 81, 56, 80, 61, 66, 86, 72, 84, 90, 91, 89, 93, 58, 92, 95, 75, 98, 96, 82, 79, 77, 101, 68, 83, 70, 85, 107, 87, 88, 76, 94, 111, 113, 97, 114, 109, 99, 115, 100, 103, 121, 119, 106, 123, 104, 126, 125, 127, 102, 131, 112, 108, 133, 136, 116, 135, 137, 117, 120, 105, 139, 122, 141, 124, 110, 144, 130, 145, 128, 129, 146, 132, 118, 155, 156, 138, 158, 140, 154, 160, 161, 159, 163, 143, 165, 164, 166, 134, 169, 170, 151, 153, 150, 149, 173, 157, 142, 179, 177, 178, 162, 147, 148, 183, 185, 152, 186, 167, 171, 187, 172, 174, 195, 191, 168, 175, 176, 199, 197, 180, 200, 181, 203, 204, 206, 188, 208, 207, 192, 189, 194, 193, 209, 210, 196, 182, 218, 216, 184, 221, 222, 223, 224, 205, 190, 202, 226, 228, 227, 211, 198, 230, 212, 213, 236, 201, 233, 217, 215, 219, 220, 240, 241, 242, 244, 246, 245, 225, 214, 229, 232, 231, 234, 235, 238, 256, 258, 254, 259, 239, 260, 261, 262, 237, 264, 265, 247, 249, 251, 263, 270, 272, 273, 248, 275, 253, 277, 243, 257, 276, 255, 282, 266, 285, 250, 284, 252, 267, 290, 288, 274, 271, 269, 292, 294, 296, 279, 280, 299, 300, 303, 268, 286, 283, 305, 281, 306, 289, 308, 309, 310, 278, 313, 311, 295, 315, 318, 319, 293, 297, 298, 287, 304, 324, 323, 291, 326, 325, 329, 331, 312, 328, 317, 314, 333, 316, 302, 301, 322, 338, 320, 321, 307, 345, 346, 327, 347, 330, 350, 348, 351, 352, 336, 353, 354, 335, 357, 358, 356, 340, 361, 362, 343, 363, 342, 341, 332, 367, 334, 349, 371, 337, 373, 339, 360, 375, 377, 344, 378, 359, 365, 379, 364, 366, 387, 383, 370, 386, 368, 355, 389, 369, 391, 395, 372, 394, 398, 380, 396, 399, 384};
int g22[] = {20, 3, 7, 24, 22, 2, 28, 11, 27, 15, 31, 35, 34, 33, 1, 36, 18, 39, 23, 21, 19, 41, 25, 46, 30, 50, 42, 49, 32, 51, 17, 26, 29, 54, 37, 58, 40, 55, 62, 63, 43, 64, 47, 44, 65, 66, 69, 45, 67, 73, 74, 38, 56, 75, 57, 77, 52, 53, 80, 60, 83, 82, 48, 70, 59, 88, 89, 90, 92, 87, 71, 96, 68, 61, 95, 76, 79, 84, 81, 78, 102, 104, 103, 106, 85, 72, 109, 108, 91, 113, 110, 98, 97, 114, 100, 99, 101, 94, 86, 122, 121, 123, 124, 107, 127, 129, 93, 130, 112, 126, 115, 133, 111, 137, 138, 117, 142, 118, 105, 119, 125, 143, 144, 128, 145, 132, 148, 150, 147, 116, 151, 152, 131, 155, 120, 134, 136, 135, 160, 140, 141, 162, 166, 167, 163, 169, 170, 165, 164, 172, 153, 146, 139, 149, 175, 156, 157, 158, 154, 182, 161, 185, 186, 184, 188, 173, 189, 191, 192, 190, 174, 171, 193, 159, 176, 177, 180, 183, 197, 179, 178, 205, 168, 203, 187, 181, 206, 212, 210, 208, 196, 214, 198, 195, 213, 217, 200, 194, 220, 224, 201, 207, 223, 228, 226, 225, 209, 229, 202, 232, 234, 230, 199, 233, 237, 215, 204, 219, 238, 241, 239, 242, 245, 218, 211, 227, 248, 250, 252, 216, 253, 231, 235, 256, 221, 222, 257, 258, 262, 240, 236, 243, 246, 266, 263, 244, 249, 270, 271, 255, 272, 275, 251, 254, 259, 279, 260, 261, 281, 278, 247, 269, 265, 267, 268, 288, 286, 291, 290, 276, 273, 296, 294, 297, 295, 298, 277, 274, 264, 300, 280, 282, 284, 285, 289, 306, 292, 287, 293, 312, 313, 314, 315, 316, 317, 299, 283, 301, 302, 324, 304, 321, 307, 325, 308, 303, 330, 305, 333, 310, 334, 309, 318, 335, 319, 320, 337, 339, 340, 342, 322, 323, 344, 345, 328, 311, 329, 326, 331, 327, 353, 332, 356, 351, 358, 336, 355, 360, 354, 357, 359, 362, 347, 338, 364, 341, 350, 348, 349, 369, 346, 374, 375, 352, 377, 376, 343, 378, 361, 383, 381, 382, 366, 363, 368, 372, 389, 393, 390, 392, 365, 371, 370, 396, 367, 397, 379, 373, 398, 380, 402, 400, 388, 384, 404, 387, 391, 408, 406, 386, 412, 395, 394, 399, 415, 419, 418, 417, 385, 420, 424, 423, 407, 405, 403, 425, 409, 430, 414, 411, 426, 433, 416, 434, 401, 410, 413, 438, 421, 442, 443, 439, 446, 447, 427, 448, 431, 428, 449, 450, 453, 429, 451, 435, 457, 422, 440, 459, 441, 461, 436, 437, 464, 444, 467, 466, 432, 454, 471, 472, 473, 474, 476, 477, 455, 480, 452, 445, 479, 460, 463, 458, 465, 462, 468, 488, 486, 490, 469, 456, 493, 492, 475, 497, 494, 482, 481, 498, 484, 483, 485, 478, 470, 506, 505, 507, 508, 491, 511, 513, 514, 515, 496, 510, 499, 517, 495, 521, 522, 501, 487, 502, 489, 503, 509, 527, 528, 512, 529, 516, 532, 534, 531, 500, 535, 536, 520, 539, 504, 518, 523, 519, 544, 524, 525, 546, 550, 526, 547, 553, 551, 549, 548, 554, 537, 530, 560, 533, 559, 540, 541, 542, 538, 566, 545, 569, 570, 568, 572, 557, 573, 575, 556, 574, 558, 555, 577, 543, 582, 561, 564, 567, 581, 563, 562, 589, 552, 587, 571, 565, 590, 596, 594, 592, 580, 576, 599, 579, 597, 601, 584, 578, 604, 608, 585, 591, 607, 612, 610, 609, 593, 613, 586, 616, 618, 614, 583, 617, 621, 622, 588, 598, 623, 625, 627, 626, 629, 602, 595, 611, 632, 634, 636, 600, 637, 615, 619, 603, 605, 606, 641, 642, 646, 624, 620, 649, 630, 650, 647, 628, 633, 654, 655, 639, 656, 659, 635, 638, 643, 663, 644, 645, 665, 662, 631, 653, 669, 651, 652, 672, 670, 675, 674, 640, 657, 680, 660, 681, 678, 682, 661, 658, 648, 684, 664, 666, 668, 671, 673, 690, 676, 692, 677, 696, 679, 698, 699, 700, 701, 683, 667, 685, 686, 708, 688, 705, 691, 709, 712, 687, 714, 689, 717, 694, 718, 693, 697, 719, 703, 704, 721, 702, 724, 726, 706, 707, 728, 729, 731, 695, 713, 710, 715, 711, 737, 716, 740, 735, 742, 720, 739, 723, 738, 741, 743, 746, 749, 722, 748, 725, 734, 732, 733, 753, 730, 758, 759, 736, 761, 760, 727, 762, 745, 767, 765, 766, 750, 747, 752, 756, 773, 777, 774, 776, 778, 755, 754, 780, 744, 781, 763, 757, 782, 764, 751, 784, 772, 768};
int g23[] = {-23, -15, -18, -33, -14, 5, 7, 10, 8, -27, 13, 12, 14, 15, -6, -3, -2, -12, 20, 16, 2, -1, 23, 25, 1, 9, 24, 28, 26, -7, 6, 33, 11, 17, 35, 37, 38, 39, 18, 3, 4, 43, 22, 46, 45, 19, 27, 30, 48, 52, 32, 51, 53, 31, 55, 56, 34, 21, 40, 61, 62, 44, 36, 41, 65, 67, 29, 47, 50, 66, 68, 75, 73, 57, 54, 60, 58, 49, 42, 82, 59, 83, 84, 64, 85, 86, 88, 89, 70, 92, 63, 94, 71, 93, 95, 97, 98, 99, 76, 72, 77, 79, 103, 105, 104, 69, 108, 91, 110, 107, 111, 74, 115, 116, 78, 90, 96, 80, 81, 102, 122, 123, 87, 120, 124, 125, 127, 129, 106, 130, 131, 112, 134, 135, 114, 117, 100, 109, 101, 119, 142, 138, 139, 146, 121, 118, 145, 149, 148, 113, 126, 153, 152, 137, 154, 136, 133, 140, 141, 144, 163, 132, 165, 143, 167, 128, 168, 147, 171, 172, 170, 151, 173, 174, 155, 150, 175, 156, 176, 160, 178, 157, 164, 184, 162, 161, 166, 169, 191, 187, 189, 193, 194, 195, 158, 159, 192, 197, 179, 177, 182, 203, 202, 181, 205, 206, 207, 208, 190, 185, 188, 213, 214, 215, 216, 198, 180, 199, 217, 183, 218, 221, 186, 225, 224, 209, 227, 229, 231, 232, 212, 233, 196, 204, 235, 210, 237, 200, 201, 222, 238, 219, 220, 245, 226, 223, 230, 211, 250, 251, 249, 254, 255, 252, 228, 240, 234, 236, 258, 239, 242, 257, 263, 241, 266, 244, 246, 247, 248, 270, 269, 253, 273, 274, 276, 256, 277, 260, 280, 279, 243, 261, 282, 265, 262, 285, 259, 289, 272, 267, 268, 264, 290, 271, 275, 297, 296, 281, 299, 283, 278, 300, 284, 304, 306, 307, 286, 309, 287, 305, 310, 291, 288, 315, 308, 312, 316, 318, 294, 295, 298, 302, 320, 324, 325, 301, 329, 327, 292, 293, 303, 311, 314, 330, 334, 337, 313, 339, 340, 341, 342, 343, 326, 323, 344, 349, 347, 348, 328, 350, 332, 336, 331, 333, 317, 335, 319, 354, 321, 322, 362, 363, 364, 365, 366, 367, 368, 346, 369, 371, 372, 352, 373, 356, 375, 338, 355, 353, 358, 359, 360, 345, 379, 384, 361, 387, 386, 351, 370, 389, 391, 394, 392, 357, 376, 396, 398, 397, 378, 381, 382, 377, 380, 400, 406, 383, 407, 409, 385, 374, 408, 412, 410, 413, 390, 417, 395, 401, 419, 421, 422, 423, 402, 399, 388, 404, 428, 430, 429, 393, 403, 414, 432, 411, 416, 436, 435, 415, 439, 440, 418, 405, 424, 427, 446, 447, 420, 425, 450, 451, 452, 431, 434, 449, 456, 437, 457, 441, 438, 444, 442, 433, 426, 445, 443, 467, 465, 448, 469, 470, 472, 473, 454, 476, 474, 478, 455, 477, 459, 481, 479, 482, 460, 485, 461, 463, 487, 466, 488, 453, 493, 475, 494, 491, 492, 458, 499, 468, 462, 498, 480, 464, 500, 486, 506, 483, 471, 504, 508, 509, 511, 513, 490, 514, 515, 496, 518, 519, 520, 489, 484, 521, 495, 503, 526, 522, 523, 529, 505, 502, 530, 533, 532, 497, 510, 537, 536, 501, 538, 540, 517, 524, 525, 507, 547, 516, 549, 527, 528, 512, 552, 531, 551, 554, 555, 535, 556, 557, 539, 534, 559, 561, 560, 544, 562, 541, 548, 568, 546, 545, 550, 553, 575, 571, 573, 576, 578, 579, 542, 543, 580, 581, 563, 558, 566, 587, 586, 565, 589, 590, 591, 592, 574, 569, 572, 597, 598, 599, 600, 582, 564, 583, 602, 567, 606, 577, 570, 609, 608, 593, 611, 613, 615, 616, 596, 617, 595, 588, 601, 594, 621, 584, 585, 607, 622, 603, 604, 629, 610, 628, 614, 633, 634, 635, 636, 619, 638, 639, 612, 624, 618, 605, 642, 623, 626, 641, 627, 625, 650, 648, 630, 631, 632, 654, 653, 637, 656, 620, 657, 640, 661, 644, 664, 663, 646, 645, 666, 647, 668, 669, 643, 673, 649, 651, 652, 677, 658, 655, 659, 681, 680, 665, 683, 667, 662, 684, 687, 688, 670, 660, 693, 694, 671, 689, 674, 675, 672, 699, 692, 696, 700, 701, 678, 679, 682, 686, 704, 708, 710, 685, 713, 711, 676, 690, 714, 695, 698, 716, 691, 721, 697, 722, 723, 725, 718, 726, 702, 707, 728, 733, 731, 732, 709, 734, 712, 720, 715, 717, 740, 719, 703, 738, 705, 706, 746, 724, 747, 727, 748, 749, 752, 730, 751, 755, 757, 736, 758, 759, 760, 729, 739, 737, 742, 743, 744, 764, 763, 768};
int g24[] = {1, 2, 3, -25, 4, -34, -33, -14, -19, -17, -9, -28, -12, 15, 12, 14, 17, 19, -8, 20, -3, 21, 23, 25, 5, 28, 22, 29, -10, 7, -1, 8, 31, 33, 32, 37, 13, 36, 40, 39, 18, 16, 11, 27, 6, 45, 9, 48, 10, 24, 46, 51, 26, 53, 55, 56, 57, 58, 59, 38, 62, 63, 44, 41, 42, 43, 35, 68, 70, 30, 71, 34, 50, 47, 76, 74, 73, 52, 77, 82, 80, 60, 64, 84, 61, 67, 88, 86, 49, 66, 89, 69, 54, 93, 72, 97, 94, 99, 79, 100, 101, 102, 103, 105, 65, 75, 85, 87, 78, 108, 91, 92, 83, 90, 114, 96, 120, 112, 118, 81, 122, 95, 104, 107, 124, 125, 127, 98, 106, 128, 109, 113, 110, 135, 136, 133, 138, 115, 117, 141, 121, 140, 144, 126, 142, 119, 145, 123, 149, 111, 129, 130, 153, 132, 154, 116, 157, 156, 158, 137, 163, 161, 139, 160, 167, 162, 168, 143, 171, 131, 147, 155, 134, 150, 175, 152, 176, 151, 179, 178, 182, 148, 183, 159, 146, 186, 185, 166, 169, 187, 190, 193, 170, 192, 173, 195, 196, 172, 198, 202, 199, 177, 164, 165, 181, 180, 207, 188, 208, 210, 189, 211, 174, 191, 216, 217, 194, 200, 214, 197, 220, 221, 184, 225, 226, 224, 223, 209, 205, 228, 204, 212, 233, 234, 231, 213, 237, 215, 201, 218, 238, 203, 241, 245, 206, 246, 247, 248, 250, 251, 229, 222, 252, 253, 235, 254, 232, 219, 227, 240, 261, 257, 263, 242, 266, 239, 264, 230, 265, 244, 270, 243, 273, 275, 236, 276, 277, 278, 280, 255, 260, 256, 259, 267, 262, 285, 286, 249, 287, 268, 272, 269, 293, 294, 295, 297, 274, 258, 271, 279, 300, 302, 301, 281, 282, 283, 284, 288, 289, 290, 312, 313, 314, 292, 315, 291, 316, 318, 319, 298, 320, 321, 322, 303, 325, 326, 299, 308, 296, 306, 307, 305, 334, 310, 336, 335, 337, 311, 309, 341, 333, 340, 304, 317, 345, 324, 344, 349, 346, 348, 332, 327, 328, 354, 323, 352, 357, 331, 330, 338, 360, 363, 339, 365, 362, 342, 368, 371, 329, 343, 366, 372, 350, 374, 375, 347, 378, 353, 355, 381, 361, 358, 382, 384, 385, 387, 388, 359, 389, 351, 391, 370, 392, 367, 393, 356, 398, 399, 397, 400, 402, 403, 404, 364, 406, 407, 408, 369, 409, 411, 410, 373, 383, 413, 376, 377, 415, 417, 379, 380, 422, 420, 396, 423, 386, 426, 395, 430, 390, 412, 431, 432, 394, 434, 433, 436, 437, 438, 439, 416, 401, 441, 421, 405, 446, 427, 428, 425, 450, 451, 419, 424, 454, 414, 456, 418, 458, 459, 435, 460, 457, 445, 461, 440, 463, 444, 448, 468, 429, 443, 472, 447, 473, 476, 474, 453, 475, 455, 478, 477, 442, 482, 464, 485, 483, 486, 487, 488, 449, 465, 469, 452, 462, 494, 495, 471, 467, 479, 498, 480, 481, 496, 502, 504, 506, 466, 507, 484, 508, 470, 489, 490, 511, 492, 493, 497, 518, 519, 520, 500, 522, 499, 501, 525, 505, 524, 528, 510, 526, 491, 530, 503, 533, 534, 513, 514, 538, 516, 509, 541, 542, 540, 543, 521, 547, 545, 523, 544, 529, 546, 552, 512, 553, 515, 531, 517, 527, 557, 539, 536, 560, 535, 563, 562, 566, 532, 567, 568, 569, 551, 571, 550, 575, 572, 574, 537, 554, 576, 577, 579, 580, 556, 582, 586, 583, 559, 548, 549, 565, 564, 591, 592, 593, 555, 573, 595, 558, 596, 600, 561, 578, 584, 598, 581, 601, 604, 607, 609, 570, 608, 611, 613, 589, 612, 588, 615, 617, 618, 619, 597, 621, 599, 585, 594, 622, 587, 625, 605, 590, 606, 630, 610, 634, 635, 636, 614, 638, 639, 640, 641, 602, 603, 620, 616, 645, 642, 624, 648, 626, 623, 627, 633, 649, 628, 654, 632, 629, 631, 658, 657, 637, 661, 664, 665, 644, 666, 643, 651, 670, 646, 671, 673, 650, 652, 667, 653, 647, 678, 677, 656, 681, 682, 655, 663, 660, 684, 662, 668, 690, 689, 669, 672, 676, 674, 693, 696, 679, 659, 697, 675, 700, 685, 702, 704, 705, 706, 707, 687, 686, 710, 683, 692, 680, 691, 715, 717, 718, 694, 698, 719, 721, 695, 723, 699, 722, 703, 688, 728, 729, 708, 701, 733, 730, 711, 716, 713, 712, 738, 714, 720, 741, 736, 742, 745, 725, 746, 747, 709, 748, 726, 752, 755, 753, 727, 750, 757, 732, 724, 739, 731, 762, 737, 761, 744, 763, 764, 766, 768};
int g25[] = {5, 25, -15, 26, 27, 28, 1, 6, 30, 32, 31, 8, -5, 34, 36, 37, 40, 20, 42, 39, 15, 4, 22, 48, 23, 51, 46, 11, 21, 52, 35, 55, 54, 56, 29, 18, 58, 59, 63, 64, 41, 65, 24, 68, 44, 69, 47, 71, 67, 50, 33, 74, 49, 45, 53, 38, 80, 62, 82, 83, 43, 61, 84, 86, 87, 66, 89, 91, 93, 90, 92, 97, 75, 95, 57, 76, 73, 60, 77, 79, 78, 105, 101, 107, 104, 106, 81, 109, 70, 114, 72, 116, 113, 117, 118, 115, 96, 119, 102, 99, 103, 121, 85, 128, 129, 108, 88, 130, 132, 131, 110, 133, 94, 138, 139, 135, 98, 100, 137, 142, 112, 122, 144, 120, 147, 125, 150, 126, 111, 124, 151, 152, 156, 158, 134, 159, 140, 136, 160, 164, 165, 123, 143, 127, 149, 146, 168, 171, 141, 172, 148, 175, 166, 178, 155, 177, 180, 176, 179, 182, 161, 162, 145, 154, 163, 183, 167, 191, 188, 170, 174, 153, 169, 194, 198, 157, 197, 199, 202, 173, 181, 203, 204, 206, 207, 186, 185, 184, 213, 210, 190, 192, 189, 215, 216, 218, 219, 220, 193, 225, 222, 195, 226, 201, 228, 187, 230, 231, 205, 233, 208, 209, 211, 212, 196, 237, 240, 200, 239, 241, 223, 224, 221, 214, 246, 247, 249, 251, 229, 252, 253, 255, 254, 232, 257, 217, 236, 258, 262, 244, 245, 238, 264, 268, 227, 265, 250, 271, 248, 274, 272, 234, 235, 276, 277, 279, 280, 256, 259, 242, 243, 282, 286, 260, 263, 266, 269, 273, 261, 289, 267, 270, 296, 298, 293, 299, 300, 275, 281, 301, 302, 304, 305, 278, 308, 309, 306, 284, 288, 312, 310, 314, 290, 313, 291, 285, 294, 320, 295, 324, 283, 292, 321, 326, 328, 287, 330, 297, 333, 303, 307, 315, 311, 337, 334, 316, 339, 317, 323, 318, 340, 341, 345, 343, 348, 325, 351, 349, 329, 332, 331, 322, 357, 353, 359, 319, 356, 338, 360, 336, 364, 363, 365, 366, 342, 327, 347, 372, 373, 374, 346, 375, 335, 377, 355, 352, 380, 378, 358, 383, 384, 344, 386, 385, 361, 387, 367, 394, 350, 370, 371, 354, 395, 397, 362, 398, 401, 381, 399, 376, 404, 402, 382, 407, 389, 368, 369, 409, 410, 412, 388, 390, 415, 396, 391, 392, 379, 422, 420, 403, 425, 400, 427, 393, 429, 426, 406, 431, 408, 434, 428, 435, 430, 436, 413, 405, 414, 418, 437, 416, 423, 419, 446, 447, 444, 424, 450, 453, 451, 411, 454, 432, 455, 457, 417, 456, 433, 461, 439, 421, 440, 464, 465, 466, 469, 445, 468, 470, 449, 448, 474, 442, 452, 471, 476, 480, 438, 479, 441, 460, 443, 481, 458, 463, 486, 459, 488, 491, 492, 467, 473, 475, 494, 472, 497, 500, 501, 502, 478, 462, 503, 505, 485, 483, 487, 477, 510, 511, 512, 513, 515, 493, 516, 490, 518, 498, 495, 496, 499, 522, 482, 484, 525, 527, 504, 506, 489, 530, 531, 509, 533, 535, 507, 508, 537, 536, 514, 542, 543, 539, 519, 520, 544, 521, 523, 547, 524, 526, 549, 528, 553, 555, 529, 552, 517, 532, 550, 540, 560, 541, 565, 566, 563, 567, 545, 546, 571, 538, 548, 570, 551, 575, 574, 534, 558, 561, 557, 580, 556, 564, 581, 559, 582, 586, 589, 587, 588, 591, 592, 593, 569, 554, 598, 572, 597, 576, 573, 562, 600, 579, 603, 604, 577, 609, 606, 610, 568, 585, 612, 584, 590, 594, 596, 616, 618, 614, 578, 619, 595, 623, 624, 583, 625, 626, 602, 608, 605, 607, 630, 631, 634, 615, 613, 635, 637, 639, 638, 599, 601, 617, 620, 642, 646, 647, 629, 622, 641, 651, 611, 621, 653, 628, 657, 655, 654, 627, 658, 659, 663, 664, 665, 640, 643, 633, 668, 666, 669, 644, 672, 632, 670, 648, 636, 645, 675, 680, 649, 679, 681, 682, 683, 684, 687, 685, 661, 689, 662, 650, 660, 652, 690, 674, 677, 656, 694, 699, 696, 697, 701, 703, 702, 705, 673, 708, 667, 676, 686, 710, 713, 671, 688, 714, 691, 712, 716, 678, 700, 698, 718, 721, 693, 706, 725, 727, 704, 729, 707, 730, 711, 709, 692, 733, 735, 734, 695, 740, 741, 738, 739, 743, 724, 744, 746, 715, 717, 748, 731, 751, 726, 732, 750, 756, 757, 754, 737, 758, 719, 761, 720, 762, 722, 723, 742, 736, 766, 728, 770, 747, 745, 771, 775, 778, 752, 777, 755, 749, 759, 781, 780, 782, 785, 765, 784, 760, 764, 787, 767, 768};
void cal()
{
	bool vis[5000];
	for (int i = 1; i < 26; i++)
		for (int j = 1; j <= 1801; j++)
		{
			memset(vis, 0, sizeof(vis));
			for (int k = 1; k < j; k++)
				vis[sg[i][j - k]] = 1;
			for (int k = 1; k < i; k++)
				vis[sg[i - k][j]] = 1;
			for (int k = 1; k < i && k < j; k++)
				vis[sg[i - k][j - k]] = 1;
			for (int k = 0;; k++)
				if (vis[k] == 0)
				{
					sg[i][j] = k;
					break;
				}
		}
}
long long f(int x, long long y)
{
	if (y < 1800)
		return sg[x][y];
	if (x == 1)
		return sg[1][1799] + (y - 1800) / per[1] * g1[0] + g1[(y - 1800) % per[1]];
	if (x == 2)
		return sg[2][1799] + (y - 1800) / per[2] * g2[per[2] - 1] + g2[(y - 1800) % per[2]];
	if (x == 3)
		return sg[3][1799] + (y - 1800) / per[3] * g3[per[3] - 1] + g3[(y - 1800) % per[3]];
	if (x == 4)
		return sg[4][1799] + (y - 1800) / per[4] * g4[per[4] - 1] + g4[(y - 1800) % per[4]];
	if (x == 5)
		return sg[5][1799] + (y - 1800) / per[5] * g5[per[5] - 1] + g5[(y - 1800) % per[5]];
	if (x == 6)
		return sg[6][1799] + (y - 1800) / per[6] * g6[per[6] - 1] + g6[(y - 1800) % per[6]];
	if (x == 7)
		return sg[7][1799] + (y - 1800) / per[7] * g7[per[7] - 1] + g7[(y - 1800) % per[7]];
	if (x == 8)
		return sg[8][1799] + (y - 1800) / per[8] * g8[per[8] - 1] + g8[(y - 1800) % per[8]];
	if (x == 9)
		return sg[9][1799] + (y - 1800) / per[9] * g9[per[9] - 1] + g9[(y - 1800) % per[9]];
	if (x == 10)
		return sg[10][1799] + (y - 1800) / per[10] * g10[per[10] - 1] + g10[(y - 1800) % per[10]];
	if (x == 11)
		return sg[11][1799] + (y - 1800) / per[11] * g11[per[11] - 1] + g11[(y - 1800) % per[11]];
	if (x == 12)
		return sg[12][1799] + (y - 1800) / per[12] * g12[per[12] - 1] + g12[(y - 1800) % per[12]];
	if (x == 13)
		return sg[13][1799] + (y - 1800) / per[13] * g13[per[13] - 1] + g13[(y - 1800) % per[13]];
	if (x == 14)
		return sg[14][1799] + (y - 1800) / per[14] * g14[per[14] - 1] + g14[(y - 1800) % per[14]];
	if (x == 15)
		return sg[15][1799] + (y - 1800) / per[15] * g15[per[15] - 1] + g15[(y - 1800) % per[15]];
	if (x == 16)
		return sg[16][1799] + (y - 1800) / per[16] * g16[per[16] - 1] + g16[(y - 1800) % per[16]];
	if (x == 17)
		return sg[17][1799] + (y - 1800) / per[17] * g17[per[17] - 1] + g17[(y - 1800) % per[17]];
	if (x == 18)
		return sg[18][1799] + (y - 1800) / per[18] * g18[per[18] - 1] + g18[(y - 1800) % per[18]];
	if (x == 19)
		return sg[19][1799] + (y - 1800) / per[19] * g19[per[19] - 1] + g19[(y - 1800) % per[19]];
	if (x == 20)
		return sg[20][1799] + (y - 1800) / per[20] * g20[per[20] - 1] + g20[(y - 1800) % per[20]];
	if (x == 21)
		return sg[21][1799] + (y - 1800) / per[21] * g21[per[21] - 1] + g21[(y - 1800) % per[21]];
	if (x == 22)
		return sg[22][1799] + (y - 1800) / per[22] * g22[per[22] - 1] + g22[(y - 1800) % per[22]];
	if (x == 23)
		return sg[23][1799] + (y - 1800) / per[23] * g23[per[23] - 1] + g23[(y - 1800) % per[23]];
	if (x == 24)
		return sg[24][1799] + (y - 1800) / per[24] * g24[per[24] - 1] + g24[(y - 1800) % per[24]];
	if (x == 25)
		return sg[25][1799] + (y - 1800) / per[25] * g25[per[25] - 1] + g25[(y - 1800) % per[25]];
}
int main()
{
	int t;
	scanf("%d", &t);
	cal();
	while (t--)
	{
		int n, x;
		long long sum = 0, y;
		scanf("%*d%*d%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%lld", &x, &y), sum ^= f(x, y);
		if (sum)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
