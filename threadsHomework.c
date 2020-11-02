//上次的6個方法，建6個thread，每個thread去執行一個方法
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//定義thread
#define NUM_THREADS 6

struct thread_data
{
    int start;
    int end;
};

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("\nHello World! It's me, thread #%ld!", tid);
    pthread_exit(NULL);
}

void *addNumber(void *data)
{
    //解指標 (dereference)
    //使用 -> (箭號)
    int thisStart = ((struct thread_data *)data)->start;
    int thisEnd = ((struct thread_data *)data)->end;

    //或是這樣取值
    int *input = (int *) data; // 取得資料
    thisStart = input[0];
    thisEnd = input[1];
    int total = 0;
    
    for (int i = thisStart; i <= thisEnd; i++)
    {
        total = i + total;
    }
    printf("\naddNumber:%d", total);
    pthread_exit(NULL);
}

void *multiplication(void *data)
{
    int thisStart = ((struct thread_data *)data)->start;
    int thisEnd = ((struct thread_data *)data)->end;

    long total = 1;

    for (int i = (long)thisStart; i <= (long)thisEnd; i++)
    {
        total = total * i;
    }
    printf("\nmultiplication:%zu ", total);
    pthread_exit(NULL);
}

void *gcd(void *data)
{
    int thisStart = ((struct thread_data *)data)->start;
    int thisEnd = ((struct thread_data *)data)->end;
    int inputSize = 0;

    for (int i = thisStart; i <= thisEnd; i++)
    {
        inputSize++;
    }
    //printf("\ninputSize:%d", inputSize);

    int x[inputSize];
    int i;
    int startTemp = thisStart;
    for (i = 0; i < inputSize; i++)
    {
        x[i] = startTemp;
        startTemp = startTemp + 1;
    }

    int j = 0;
    for (i = 0; i < inputSize; i++)
    {
        //printf("\nx[%d] is %d", i, x[i]);
        int q;
        int temp;
        for (q = x[i]; q > 0; q--)
        {
            if (x[i] % q == 0 && q != 1 && q != 0)
            {
                temp = q;
            }
        }
        //陣列內放入每個數字的最小因數
        x[i] = temp;
    }

    _Bool isTrue = 0;
    int lastTemp = 0;
    for (i = 0; i < inputSize; i++)
    {
        //如果數字全一樣，才代表有1以外的公因數,有其中一個不一樣gcd=1
        if (lastTemp != x[i])
        {
            isTrue = 1;
        }

        lastTemp = x[i];
    }
    if (isTrue == 1)
    {
        printf("\ngcp is 1");
    }
    else
    {
        printf("\ngcp is %d", lastTemp);
    }

    pthread_exit(NULL);
}

void twoNumberGcd(void *data)
{
    int thisStart = ((struct thread_data *)data)->start;
    int thisEnd = ((struct thread_data *)data)->end;

    long gcd = 0;
    //質因數2開始
    for (int k = 1; k <= thisStart && k <= thisEnd; ++k)
    {
        if (thisStart % k == 0 && thisEnd % k == 0)
        {
            gcd = k;
            //printf("\ngcd:%d", gcd);
        }
    }
    printf("\n%d and %d gcd is %zu", thisStart, thisEnd, gcd);
    pthread_exit(NULL);
}

long twoNumberGcd_2(long start, long end)
{
    long gcd = 0;
    //質因數2開始
    for (int k = 1; k <= start && k <= end; ++k)
    {
        if (start % k == 0 && end % k == 0)
        {
            gcd = k;
            //printf("\ngcd:%d", gcd);
        }
    }
    // printf("\n%zu 和 %zu gcd is %zu", n1, n2, gcd);

    return gcd;
}

int twoNumberLcm(void *data)
{
    int thisStart = ((struct thread_data *)data)->start;
    int thisEnd = ((struct thread_data *)data)->end;

    long gcd = twoNumberGcd_2(thisStart, thisEnd);
    //10*20/10=20
    long lcm = (thisStart * thisEnd) / gcd;

    printf("\n%d and %d lcm is %zu", thisStart, thisEnd, lcm);

    pthread_exit(NULL);
}

void findAdd(void *data)
{
    int thisStart = ((struct thread_data *)data)->start;
    int thisEnd = ((struct thread_data *)data)->end;
    // printf("\n %zu", n1);
    // printf("\n %zu", n2);

    if (thisStart == 0 || thisEnd == 0)
    {
        printf("\n error");
    }

    int addSize = 0;

    for (int i = thisStart; i <= thisEnd; i++)
    {
        if (i % 2 != 0)
        {
            //算奇數有幾個
            //printf("%d",i);
            addSize++;
        }
    }
    //printf("\naddSize %d", addSize);

    int addArray[addSize];

    int n1Temp = thisStart;
    for (int i = 0; i < addSize; i++)
    {
        if (n1Temp % 2 == 0)
        {
            n1Temp = n1Temp + 1;
            addArray[i] = n1Temp;
        }
        else
        {
            n1Temp = n1Temp + 2;
            addArray[i] = n1Temp;
        }
    }

    printf("\nadd  is ");
    for (int i = 0; i < addSize; i++)
    {
        //printf("\n addArray[%d] is %d", i, addArray[i]);
        printf("%d  ", addArray[i]);
    }

    pthread_exit(NULL);
}

int findEven(void *data)
{
    int thisStart = ((struct thread_data *)data)->start;
    int thisEnd = ((struct thread_data *)data)->end;
    // printf("\n %zu", n1);
    // printf("\n %zu", n2);

    if (thisStart == 0 || thisEnd == 0)
    {
        printf("\n error");
    }

    int evenSize = 0;

    for (int i = thisStart; i <= thisEnd; i++)
    {
        if (i % 2 != 0)
        {
            //printf("%d",i);
            //算奇數有幾個
            evenSize++;
        }
    }
    //printf("\nevenSize %d", evenSize);

    int evenArray[evenSize];

    int n1Temp = thisStart;
    for (int i = 0; i < evenSize; i++)
    {
        if (n1Temp % 2 != 0)
        {
            n1Temp = n1Temp + 1;
            evenArray[i] = n1Temp;
        }
        else
        {
            n1Temp = n1Temp + 2;
            evenArray[i] = n1Temp;
        }
    }

    printf("\neven is ");
    for (int i = 0; i < evenSize; i++)
    {
        //printf("\n evenArray[%d] is %d", i, evenArray[i]);
        printf("%d  ", evenArray[i]);
    }

    // return NULL;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{

    int start, end;
    printf("\nEnter start:");
    scanf("%d", &start);
    printf("\nEnter end:");
    scanf("%d", &end);

    int data[2] = {start, end};
    // struct thread_data data;
    // data.start = start;
    // data.end = end;

    printf("\n輸入start:%d", start);
    printf("\n輸入end:%d", end);

    // threads
    pthread_t threads[NUM_THREADS];
    // malloc配置記憶體空間來存放傳回的資料
    struct thread_data *thread_array = malloc(NUM_THREADS * sizeof(struct thread_data));
    printf("\nNUM_THREADS %d", NUM_THREADS);

    int rc;
    long t;

    /*
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_array[i].start = start;
        thread_array[i].end = end;
    }
    rc = pthread_create(&threads[0], NULL, addNumber, (void *)&thread_array[0]);
    rc = pthread_create(&threads[1], NULL, multiplication, (void *)&thread_array[1]);
    rc = pthread_create(&threads[2], NULL, gcd, (void *)&thread_array[2]);
    rc = pthread_create(&threads[3], NULL, findAdd, (void *)&thread_array[3]);
    rc = pthread_create(&threads[4], NULL, findEven, (void *)&thread_array[4]);
    rc = pthread_create(&threads[5], NULL, twoNumberLcm, (void *)&thread_array[5]);
*/

    for (t = 0; t < NUM_THREADS; t++)
    {
        // thread_array[t].start = data.start;
        // thread_array[t].end = data.end;

        // printf("\nIn main: creating thread %ld\n", t);
        // rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (t == 0)
        {
            // 建立子執行緒
            rc = pthread_create(&threads[t], NULL, addNumber, (void*) data);
        }
        else if (t == 1)
        {
            rc = pthread_create(&threads[t], NULL, multiplication, (void*) data);
        }
        else if (t == 2)
        {
            rc = pthread_create(&threads[t], NULL, gcd, (void*) data);
        }
        else if (t == 3)
        {
            rc = pthread_create(&threads[t], NULL, findAdd, (void*) data);
        }
        else if (t == 4)
        {
            rc = pthread_create(&threads[t], NULL, findEven, (void*) data);
        }
        else if (t == 5)
        {
            rc = pthread_create(&threads[t], NULL, twoNumberLcm, (void*) data);
        }

        if (rc)
        {
            printf("\nERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}