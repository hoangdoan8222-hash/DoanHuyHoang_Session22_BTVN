#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student students[100];
    int count = 0;
    int choice;
    int i;
    
    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap thong tin hoc sinh\n");
        printf("2. Hien thi thong tin hoc sinh\n");
        printf("3. Tinh diem trung binh tat ca hoc sinh\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Nhap so luong hoc sinh muon them: ");
            scanf("%d", &i);
            
            int j;
            for (j = 0; j < i; j++) {
                printf("\nHoc sinh %d:\n", count + 1);
                
                printf("Nhap ten: ");
                scanf("%s", students[count].name);
                
                printf("Nhap tuoi: ");
                scanf("%d", &students[count].age);
                
                printf("Nhap diem: ");
                scanf("%f", &students[count].grade);
                
                count++;
            }
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("Chua co du lieu!\n");
            } else {
                printf("\n--- Danh sach hoc sinh ---\n");
                int k;
                for (k = 0; k < count; k++) {
                    printf("%d. Ten: %s | Tuoi: %d | Diem: %.2f\n",
                           k + 1,
                           students[k].name,
                           students[k].age,
                           students[k].grade);
                }
            }
        } 
        else if (choice == 3) {
            if (count == 0) {
                printf("Chua co du lieu!\n");
            } else {
                float sum = 0;
                int k;
                for (k = 0; k < count; k++) {
                    sum += students[k].grade;
                }
                printf("Diem trung binh: %.2f\n", sum / count);
            }
        }
        
    } while (choice != 0);
    
    return 0;
}

