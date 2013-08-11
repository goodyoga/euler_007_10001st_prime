/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <string.h>   /* strlen  */
#include <unistd.h>   /* getopt */

void usage(void);
char *prog;

int is_prime(unsigned long long int *primes, unsigned long long int ind, unsigned long long int cur, int all);

int is_prime(unsigned long long int *primes, unsigned long long int ind, unsigned long long int cur, int all)
{
    unsigned long long int i;
    unsigned long long int amari;

    for (i = 0; (i < ind) && primes[i] ; i++)
    {
        amari = cur % primes[i];
        if (0 == amari)
        {
            if (all) printf("check  : cur=%llu, index=%llu is not prime.\n", cur, ind);
            return 0;
        }
    }
    if (all) printf("check  : cur=%llu, index=%llu is a prime.\n", cur, ind);
    return 1;
}

int main(int argc, char **argv)
{
    unsigned long long int max;
    unsigned long long int *primes;
    unsigned long long int cur;
    unsigned long long int i;
    int opt, all = 0;
    char *p;
    size_t size;

    prog = argv[0];
    max = 10001;

    while ( -1 != (opt = getopt(argc, argv, "ahn:")) )
    {
        if('h' == opt)
	{
            usage();
            exit(EXIT_SUCCESS);
	}
        else if ('n' == opt)
        {
            max = strtoull(optarg, &p, 0);
        }
        else if ('a' == opt)
        {
            all = 1;
        }
    }
    
    printf("getting %llu th prime ...\n", max);

    size = sizeof(unsigned long long int) * (size_t)(max) ;
    primes = (unsigned long long int *) malloc( size );
    memset(primes, 0, size);

    i = 0;
    cur = 2;
    while ( i < max )
    {
        if (is_prime(primes, i, cur, all))
        {
            primes[i] = cur;
            i++;
        }
        cur++;
    }
    
    printf("answer: %llu th prime is %llu\n", i, primes[i-1]);
    free(primes);
    return EXIT_SUCCESS;
}



void usage(void)
{
    printf("    http://projecteuler.net/problem=7\n");
    printf("    [Problem 7] 10001st prime\n");
    printf("    By listing the first six prime numbers: 2, 3, 5, 7, 11,\n"
           "    and 13, we can see that the 6th prime is 13.\n"
           "    What is the 10 001st prime number?\n\n");
    printf("    -h: show this help\n"
           "    -a: show additional messages\n"
           "    -n <number>: solve this with max <number>\n");
    return;
}


