const int nNumStudents = 5;
int anScores[nNumStudents] = { 84, 92, 76, 81, 56 };
int nMaxScore = 0;
for (int nStudent = 0; nStudent < nNumStudents; nStudent++)
    if (anScores[nStudent] > nMaxScore)
        nMaxScore = anScores[nStudent];

cout << "The best score was " << nMaxScore << endl;