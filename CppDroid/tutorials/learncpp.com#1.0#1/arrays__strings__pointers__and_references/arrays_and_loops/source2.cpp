const int nNumStudents = 5;
int anScores[nNumStudents] = { 84, 92, 76, 81, 56 };
int nTotalScore = anScores[0] + anScores[1] + anScores[2] + anScores[3] + anScores[4];
double dAverageScore = static_cast<double>(nTotalScore) / nNumStudents;