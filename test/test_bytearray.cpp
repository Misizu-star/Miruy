#include <iostream>
#include "bytearray.h"

using namespace miruy;

void test01()
{
    ByteArray::ptr byte(new ByteArray(4));
    byte->writeInteger(1234);
    byte->writeInteger(1231u);
    std::cout << byte->readInteger<int32_t>() << "\t";
    std::cout << byte->readInteger<uint32_t>() << "\t";
    byte->writeInteger<short>(-1231);
    std::cout << byte->readInteger<short>() << "\t";
    byte->writeInteger<int64_t>(-1231);
    std::cout << byte->readInteger<int64_t>() << "\t";
    std::cout << std::endl;
}

void test02()
{
    ByteArray::ptr byte(new ByteArray(128));
    byte->writeDecimal(1.234);
    std::cout << byte->readDecimal<double>() << "\t";
    byte->writeDecimal(-1.25);
    std::cout << byte->readDecimal<double>() << "\t";
    byte->writeDecimal(1.2323f);
    std::cout << byte->readDecimal<float>() << "\t";
    byte->writeDecimal(-1.25f);
    std::cout << byte->readDecimal<float>() << "\t";
    std::cout << std::endl;
}

void test03()
{
    ByteArray::ptr byte(new ByteArray(128));
    byte->writeInteger(125);
    byte->writeInteger(250);
    int32_t v;
    byte->copy(&v, -4, 4);
    v = __bswap_32(v);
    std::cout << v << "\t";

    std::cout << std::endl;
}

void test04()
{
    ByteArray::ptr byte(new ByteArray(8));
    std::cout << "write some integers:" << std::endl;

    byte->writeInteger(1234);
    byte->writeInteger(1456);
    byte->writeInteger(-1u);
    byte->writeInteger<int64_t>(-11654);

    std::cout << "size=" << byte->getSize() << "\tcapacity=" << byte->getCapacity()
              << "\tbase_size=" << byte->getBaseSize() << std::endl;

    std::cout << std::endl << "read a int: " << byte->readInteger<int>() << std::endl;

    std::cout << "size=" << byte->getSize() << "\tcapacity=" << byte->getCapacity()
              << "\tbase_size=" << byte->getBaseSize() << std::endl;

    std::cout << std::endl << "write to file 'byte'" << std::endl;
    byte->writeToFile("byte");
    std::cout << "size=" << byte->getSize() << "\tcapacity=" << byte->getCapacity()
              << "\tbase_size=" << byte->getBaseSize() << std::endl;

    std::cout << std::endl << "write from file 'byte'" << std::endl;
    byte->readFromFile("byte");
    std::cout << "size=" << byte->getSize() << "\tcapacity=" << byte->getCapacity()
              << "\tbase_size=" << byte->getBaseSize() << std::endl;

    std::cout << std::endl
              << byte->readInteger<int>() << "\t" << byte->readInteger<int>() << "\t"
              << byte->readInteger<int64_t>() << std::endl;

    std::cout << "size=" << byte->getSize() << "\tcapacity=" << byte->getCapacity()
              << "\tbase_size=" << byte->getBaseSize() << std::endl;

    /**
     * 执行结果:
     * write some integers:
     * size=20  capacity=24 base_size=8
     *
     * read a int: 1234
     * size=16  capacity=24 base_size=8
     *
     * write to file 'byte'
     * size=0   capacity=8  base_size=8
     *
     * write from file 'byte'
     * size=16  capacity=16 base_size=8
     *
     * 1456     -1      -11654
     * size=0   capacity=8  base_size=8
     */
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}