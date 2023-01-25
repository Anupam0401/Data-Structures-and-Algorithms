// Given an integer A, you have to find the Ath Perfect Number.

// A Perfect Number has the following properties:

// It comprises only 1 and 2.

// The number of digits in a Perfect number is even.

// It is a palindrome number.

// For example, 11, 22, 112211 are Perfect numbers, where 123, 121, 782, 1 are not.


module.exports = { 
 //param A : integer
 //return a strings
	solve : function(A){
        function find(N){
            if(N<=2) return N;
            let queue=[];
            queue.push(1);
            queue.push(2);
            let count =2;
            while(count<N){
                let x = queue.shift();
                let a = x*10+1;
                let b = a+1;
                if(count+1==N) return a;
                if(count+2==N) return b;
                queue.push(a);
                queue.push(b);
                count+=2;
            }
        }
       let ans = find(A);
       let temp = ans.toString().split('').reverse().join('');
       return Number(ans+temp)
	}
};
