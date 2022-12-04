




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.




int main()
{

  clock_t start , end;

  double execution_time;

  start=clock();

  
  

  
  mavalloc_init( 75000000, NEXT_FIT );

  unsigned char* array[10000];

  for (int i=0 ; i<10000;i++)
  {
    array[i]=mavalloc_alloc(100);
  }

  for (int i=1000; i<10000;i++)
  {
    if (i%7==0)
    {
      mavalloc_free(array[i]);
    }

  }

  //free memory at the beginning

  

  // //printfList();

  for (int i=0; i<10000; i++)
  {
    if (i % 2==0 && i%3==0)
    {
      mavalloc_free(array[i]);
    }
  }

  



  char *ptr_1 = mavalloc_alloc(200000);
  char *ptr_2 = mavalloc_alloc(5000);
  char*ptr3  = mavalloc_alloc(98);
  mavalloc_alloc(1);
  mavalloc_free(ptr_2);
  mavalloc_alloc(20);


  mavalloc_free(ptr3);

  for (int i =5000 ; i<1000;i++)
  {
    if (i%5==0)
    {
      mavalloc_free(array[i]);
    }
  }

  //Add test cases

  unsigned char* second_array [400];

  for (int i=200; i<600;i++)
  {

    second_array[i]= mavalloc_alloc(i);

  }

  mavalloc_free(ptr3);


  for (int j=0; j<300;j++)
  {
    mavalloc_alloc(98*j);
  }

  mavalloc_free(ptr_1);

  for (int k=360; k<500; k++)
  {
    mavalloc_alloc(k*3);
  }

  for (int i=3000; i<4000;i++)
  {
    mavalloc_free(array[i]);
  }

  

  for (int i=0; i<10000;i++)
  {
    mavalloc_alloc(4);
  }

  end=clock();

  execution_time=((double) (end-start))/CLOCKS_PER_SEC;
 
  printf("Execution time for benchmark1.c NEXT_FIT: %f\n" , execution_time);

  //printfList();




    // //Test case 7
    
    // mavalloc_init( 75000, BEST_FIT );
    // char * ptr1    = ( char * ) mavalloc_alloc ( 65535 );
    // char * buffer1 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr4    = ( char * ) mavalloc_alloc ( 65 );
    // char * buffer2 = ( char * ) mavalloc_alloc( 1 );
    // char * ptr2    = ( char * ) mavalloc_alloc ( 1500 );
    // //printfList();

    // ////printff("%p\n" , ptr1);

    
    //  //Test case 3
     
    // // mavalloc_init( 65600, BEST_FIT );

    // // char * ptr1    = (char*)mavalloc_alloc( 65536 );
    // // char * ptr2    = (char*)mavalloc_alloc( 64 );
    // // //printfList();
     
    // // ////printff("%p\n" , ptr1);
    // // ////printff("%p\n" , ptr2);
    // // ////printff("%d\n" ,mavalloc_size());

    // //Test Case 2
    // //  mavalloc_init( 128000, BEST_FIT );
    // //  char * ptr1    = (char*)mavalloc_alloc( 65535 );
    // //  char * ptr2    = (char*)mavalloc_alloc( 65 );
    // //  //printfList();
     
    // //  ////printff("%p\n" , ptr1);
    // //  ////printff("%p\n" , ptr2);
    // //  ////printff("%d\n" ,mavalloc_size());
    // //Start with test cases for best_fit
    // //Test case 1
    // // mavalloc_init( 65535, BEST_FIT );
    // // char * ptr = ( char * ) mavalloc_alloc ( 65535 );
    // // ////printff("I allocated the whole thing\n");
    // // ////printff("The return address %p\n" , ptr );
    // // //printfList();
    
}

//When process is equal to hole size.