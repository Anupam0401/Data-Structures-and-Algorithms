int main()
{
    goto skip; // invalid forward jump
    int x = 5;
skip:
    x += 3; // what would this even evaluate to?
    return 0;
}