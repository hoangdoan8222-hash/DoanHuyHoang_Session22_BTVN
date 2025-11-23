#include <stdio.h>
#include <string.h>

struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};

struct SinhVien {
    char maSV[20];
    char hoTen[50];
    struct NgaySinh ngaysinh;
    char diaChi[100];
    char phone[15];
};

int main() {
    struct SinhVien sv[100];
    int count = 0;
    int choice;
    int i;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Tim kiem sinh vien theo ma\n");
        printf("4. Xoa sinh vien theo ma\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nhap so luong sinh vien muon them: ");
            scanf("%d", &i);

            {
                int j;
                for (j = 0; j < i; j++) {
                    printf("\nSinh vien %d:\n", count + 1);

                    printf("Ma sinh vien: ");
                    scanf("%s", sv[count].maSV);

                    printf("Ho ten: ");
                    scanf("%s", sv[count].hoTen);

                    printf("Ngay sinh (ngay thang nam): ");
                    scanf("%d %d %d", 
                        &sv[count].ngaysinh.ngay, 
                        &sv[count].ngaysinh.thang, 
                        &sv[count].ngaysinh.nam);

                    printf("Dia chi: ");
                    scanf("%s", sv[count].diaChi);

                    printf("Dien thoai: ");
                    scanf("%s", sv[count].phone);

                    count++;
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("Chua co du lieu!\n");
            } else {
                printf("\n--- Danh sach sinh vien ---\n");
                {
                    int k;
                    for (k = 0; k < count; k++) {
                        printf("%d. %s | %s | %02d/%02d/%04d | %s | %s\n",
                            k + 1,
                            sv[k].maSV,
                            sv[k].hoTen,
                            sv[k].ngaysinh.ngay,
                            sv[k].ngaysinh.thang,
                            sv[k].ngaysinh.nam,
                            sv[k].diaChi,
                            sv[k].phone);
                    }
                }
            }
        }
        else if (choice == 3) {
            char searchID[20];
            int found = 0;

            printf("Nhap ma sinh vien can tim: ");
            scanf("%s", searchID);

            {
                int k;
                for (k = 0; k < count; k++) {
                    if (strcmp(sv[k].maSV, searchID) == 0) {
                        printf("Tim thay: %s | %s | %02d/%02d/%04d | %s | %s\n",
                            sv[k].maSV,
                            sv[k].hoTen,
                            sv[k].ngaysinh.ngay,
                            sv[k].ngaysinh.thang,
                            sv[k].ngaysinh.nam,
                            sv[k].diaChi,
                            sv[k].phone);
                        found = 1;
                        break;
                    }
                }
            }

            if (!found)
                printf("Khong tim thay sinh vien!\n");
        }
        else if (choice == 4) {
            char delID[20];
            int found = 0;

            printf("Nhap ma sinh vien muon xoa: ");
            scanf("%s", delID);

            {
                int k;
                for (k = 0; k < count; k++) {
                    if (strcmp(sv[k].maSV, delID) == 0) {
                        int t;
                        for (t = k; t < count - 1; t++) {
                            sv[t] = sv[t + 1];
                        }
                        count--;
                        found = 1;
                        printf("Da xoa thanh cong!\n");
                        break;
                    }
                }
            }

            if (!found)
                printf("Khong tim thay sinh vien de xoa!\n");
        }

    } while (choice != 0);

    return 0;
}

