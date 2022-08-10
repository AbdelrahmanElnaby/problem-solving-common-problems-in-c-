//Draft for the Algorithm 

/*
		PsuedoCode
	int multiplication(a,b,n){

		if(n==1)
			return a*b;
		else
			{
			int a1=a[0..a/2-1];
			int a0=a[a/2...a.size-1];
			int b1=a[0..b/2-1];
			int b0=b[b/2...b.size-1];

			int c2=multiplication(a1,b1,n/2);
			int c0=multiplication(a0,b0,n/2);
			int c1=multiplication((a1+a0),(b1+b0),size of them)-(c2+c0);
			if(n%0!=1)
				return c2*pow(10,n+1)+c1*pow(10,(n+1)/2)+c0;
			else
				return c2*pow(10,n)+c1*pow(10,n/2)+c0;
			}

		
	}
*/