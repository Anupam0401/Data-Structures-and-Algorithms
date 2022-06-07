const int nNumStudents = 5;
int anScores[nNumStudents] = { 84, 92, 76, 81, 56 };
int nTotalScore = 0;
for (int nStudent = 0; nStudent < nNumStudents; nStudent++)
    nTotalScore += anScores[nStudent];

double dAverageScore = static_cast<double>(nTotalScore) / nNumStudents;