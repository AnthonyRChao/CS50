// This program is an implementation of Luhn's algorithm.

#include <stdio.h>
#include <cs50.h>

int main(void)
{
   printf("Number: ");
   long num = get_long_long();

   long num1_product = 0, num1_sum = 0, num2_sum = 0;
   long num0, num1, num2, test, first_check, first_two_check;
   int num0_length = 0, loop1_count = 0, loop2_count = 0;
   int digit, digit_new;

   // determine num length, first two digits of num, and first digit of num
   num0 = num;
   while (num0 > 0)
   {
      num0 = num0 / 10;
      num0_length++;
      if (num0 > 10)
      {
         first_two_check = num0;
      }
      else if (num0 > 0)
      {
         first_check = num0;
      }
   }

   // printf("num0_length: %i\n", num0_length);
   // printf("first_check: %li\n", first_check);
   // printf("first_two_check: %li\n", first_two_check);

   // loop through every other number from second to last number, multiply by 2, sum the resulting characters

   // ignore first digit
   num1 = num / 10;
   num2 = num;
   while (num1)
   {
      loop1_count++;
      digit = num1 % 10;

      // printf("loop1 #%i, ", loop1_count);
      // printf("digit is: %i, ", digit);
      // printf("num1 is initially: %li, ", num1);

      num1_product = digit * 2;

      while (num1_product)
      {
         digit_new = num1_product % 10;
         // printf("digit_new is: %i, ", digit_new);

         num1_sum = num1_sum + digit_new;
         // printf("num1_sum is: %li, ", num1_sum);

         num1_product = num1_product / 10;
      }

      num1 = num1 / 100;
      // printf("num1 is now: %li, ", num1);
      // printf("num1_product is: %li\n", num1_product);
   }

   // loop through every other number from last number, sum the resulting numbers
   while (num2)
   {
      // printf("Loop2 #%i, ", loop2_count);
      loop2_count++;

      digit = num2 % 10;
      // printf("digit is: %i, ", digit);
      // printf("Num2 is initially: %li, ", num2);

      num2_sum += digit;

      num2 = num2 / 100;
      // printf("Num2 is now: %li, ", num2);
      // printf("num2_sum is: %li\n", num2_sum);
   }

   test = num1_sum + num2_sum;
   // printf("test = %lu\n", test);

   // check logic
   if (test % 10 == 0)
   {
      if (num0_length == 15 && (first_two_check == 34 || first_two_check == 37))
      {
         printf("AMEX\n");
      }
      else if (num0_length == 16 && (first_two_check == 51 || first_two_check == 52 || first_two_check == 53 || first_two_check == 54|| first_two_check == 55))
      {
         printf("MASTERCARD\n");
      }
      else if (first_check == 4 && (num0_length == 13 || num0_length == 16))
      {
         printf("VISA\n");
      }
      else
      {
         printf("INVALID\n");
      }
   }
   else
   {
      printf("INVALID\n");
   }

   return 0;
}