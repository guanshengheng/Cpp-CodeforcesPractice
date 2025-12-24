#include <stdio.h>

// 定义一个联合体
union Data {
    int i;
    float f;
    unsigned char bytes[4]; // 假设 int 和 float 都是 4 字节
};

int main() {
    union Data data;

    printf("联合体 Data 的总大小是: %zu 字节\n", sizeof(data));
    printf("----------------------------------\n");

    // 1. 给整数赋值
    data.i = 0x41424344; // 十六进制，对应 ASCII 的 D, C, B, A
    printf("给 data.i 赋值后:\n");
    printf("整数值 i: 0x%x\n", data.i);
    printf("浮点值 f: %f\n", data.f);
    printf("字节数组 bytes: %c %c %c %c\n", data.bytes[0], data.bytes[1], data.bytes[2], data.bytes[3]);

    printf("\n----------------------------------\n");

    // 2. 修改浮点数，会发现整数和字节数组也变了
    data.f = 3.14f;
    printf("给 data.f 赋值 3.14 后:\n");
    printf("整数值 i (16进制): 0x%x\n", data.i);
    printf("字节数组 bytes: %.2x %.2x %.2x %.2x\n", data.bytes[0], data.bytes[1], data.bytes[2], data.bytes[3]);

    return 0;
}