#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phoneNumber[15];
    char email[50];
};

int main() {
    struct Contact contacts[100];
    int count = 0;
    int choice;
    int i;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Them lien he moi\n");
        printf("2. Hien thi tat ca lien he\n");
        printf("3. Tim kiem theo ten\n");
        printf("4. Xoa lien he theo ten\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nhap so luong lien he muon them: ");
            scanf("%d", &i);

            {
                int j;
                for (j = 0; j < i; j++) {
                    printf("\nLien he %d:\n", count + 1);

                    printf("Nhap ten: ");
                    scanf("%s", contacts[count].name);

                    printf("Nhap so dien thoai: ");
                    scanf("%s", contacts[count].phoneNumber);

                    printf("Nhap email: ");
                    scanf("%s", contacts[count].email);

                    count++;
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("Chua co du lieu!\n");
            } else {
                printf("\n--- Danh sach lien he ---\n");
                {
                    int k;
                    for (k = 0; k < count; k++) {
                        printf("%d. Ten: %s | SDT: %s | Email: %s\n",
                            k + 1,
                            contacts[k].name,
                            contacts[k].phoneNumber,
                            contacts[k].email);
                    }
                }
            }
        }
        else if (choice == 3) {
            char searchName[50];
            int found = 0;

            printf("Nhap ten can tim: ");
            scanf("%s", searchName);

            {
                int k;
                for (k = 0; k < count; k++) {
                    if (strcmp(contacts[k].name, searchName) == 0) {
                        printf("Tim thay: %s | %s | %s\n",
                            contacts[k].name,
                            contacts[k].phoneNumber,
                            contacts[k].email);
                        found = 1;
                    }
                }
            }

            if (!found) {
                printf("Khong tim thay lien he!\n");
            }
        }
        else if (choice == 4) {
            char delName[50];
            int found = 0;

            printf("Nhap ten muon xoa: ");
            scanf("%s", delName);

            {
                int k;
                for (k = 0; k < count; k++) {
                    if (strcmp(contacts[k].name, delName) == 0) {
                        int t;
                        for (t = k; t < count - 1; t++) {
                            contacts[t] = contacts[t + 1];
                        }
                        count--;
                        found = 1;
                        printf("Da xoa thanh cong!\n");
                        break;
                    }
                }
            }

            if (!found) {
                printf("Khong tim thay ten de xoa!\n");
            }
        }

    } while (choice != 0);

    return 0;
}

