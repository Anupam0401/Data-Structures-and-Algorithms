switch (2)
{
   case 1: // Does not match -- skipped
       cout << 1 << endl;
       break;
   case 2: // Match!  Execution begins at the next statement
       cout << 2 << endl; // Execution begins here
       break; // Break terminates the switch statement
   case 3:
       cout << 3 << endl;
       break;
   case 4:
       cout << 4 << endl;
       break;
   default:
       cout << 5 << endl;
       break;
}
// Execution resumes here