void useMyStruct(MyStruct x)
{
}

useMyStruct({2, 3.5f}); // use uniform initialization to create a MyStruct implicitly

MyStruct makeMyStruct(void)
{
    return {2, 3.5f}; // use uniform initialization to create a MyStruct implicitly
}