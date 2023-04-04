// Given an integer array A of size N and an integer B, you have to return the same array after rotating it B times towards the right.

module.exports = {
    //param A : array of integers
    //param B : integer
    //return a array of integers
    solve: function (A, B) {
        let newArr = []

        for (let i = 0; i < A.length; i++) {
            newArr[(i + B) % A.length] = A[i] // (i + B) % A.length is the new index of the element
        }
        return newArr
    }
};
