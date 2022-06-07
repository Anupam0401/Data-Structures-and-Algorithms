switch (2)
{
   case 1: // Does not match -- skipped
       cout << 1 << endl;
   case 2: // Match!  Execution begins at the next statement
       cout << 2 << endl; // Execution begins here
   case 3:
       cout << 3 << endl; // This is also executed
   case 4:
       cout << 4 << endl; // This is also executed
   default:
       cout << 5 << endl; // This is also executed
}