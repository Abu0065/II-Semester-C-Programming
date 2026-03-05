//System that automates loan processing tasks, including loan eligibility checking, interest estimation, and repayment scheduling.
#include <stdio.h>
#include <stdlib.h>
#define MAX_LOANS 100
typedef struct {
    char borrowerName[50];
    float loanAmount;
    float interestRate;
    int repaymentMonths;
} Loan;
void addLoan(Loan loanList[], int *count) {
    if (*count >= MAX_LOANS) {
        printf("Loan list is full.\n");
        return;
    }
    printf("Enter borrower name: ");
    scanf("%s", loanList[*count].borrowerName);
    printf("Enter loan amount: ");
    scanf("%f", &loanList[*count].loanAmount);
    printf("Enter interest rate (in percentage): ");
    scanf("%f", &loanList[*count].interestRate);
    printf("Enter repayment period (in months): ");
    scanf("%d", &loanList[*count].repaymentMonths);
    (*count)++;
}
void displayLoans(Loan loanList[], int count) {
    printf("Loan Details:\n");
    for (int i = 0; i < count; i++) {
        printf("Borrower: %s, Loan Amount: %.2f, Interest Rate: %.2f%%, Repayment Period: %d months\n",
               loanList[i].borrowerName, loanList[i].loanAmount, loanList[i].interestRate, loanList[i].repaymentMonths);
    }
}
int main() {
    Loan loanList[MAX_LOANS];
    int count = 0;
    char choice;
    do {
        addLoan(loanList, &count);
        printf("Do you want to add another loan? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    displayLoans(loanList, count);
    return 0;
}
