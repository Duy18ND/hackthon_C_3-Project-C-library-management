#include <stdio.h>
#include <string.h> 
#include "function.h" 
//logic ham

void Choice_Login(int *choice_login){//lua chon login
			printf("\nMoi ban lua chon : ");
			scanf("%d",choice_login);
}

void Choice_Menu(int *choice_menu){//lua chon menu
			printf("\nMoi ban lua chon : ");
			scanf("%d",choice_menu);
}

void MenuLogin(){//Menu lua chon dang nhap tai khoan
			printf("\n\t CHOOSE YOUR ROLE\n");
			printf("=========================================\n");
			printf("[1] Admin\n");
			printf("[2] User\n");
			printf("[3] New User\n");
			printf("[0] Exit The Program\n");
			printf("=========================================\n");
}

int LoginAdmin(){//login admin
			struct login logAdmin;	
		  	char checkEmail[] = "admin@email.com";  //Email cua admin
			char checkPass[] = "admin123";  // Pass cua admin
			do{//Neu nguoi dung dang nhap sai se duoc dang nhap lai
			fflush(stdin);
			printf("\n\tLOGIN\n"); 	 
			printf("================================\n");
			printf("Email: ");//Yeu cau nguoi dung nhap tai khoan
			fgets(logAdmin.Email,sizeof(logAdmin.Email),stdin);
			logAdmin.Email[strcspn(logAdmin.Email, "\n")] = '\0';//strcspn tim do dai cua chuoi ky tu
			printf("Password: ");//yeu cau nguoi dung nhap mat khau
			fgets(logAdmin.Password,sizeof(logAdmin.Password),stdin);//strcspn tim do dai cua chuoi ky tu
			logAdmin.Password[strcspn(logAdmin.Password, "\n")] = '\0';
			printf("================================\n");
			printf("\n");
			//Kiem tra tai khoan va mat khau da dung chua?

			if(strcmp(logAdmin.Email,checkEmail) ==0 && strcmp(logAdmin.Password,checkPass) == 0){//strcmp so sanh 
					printf("Ban da dang nhap thanh cong\n");
				return 1;
			}else{
					printf("Dang Nhap khong thanh cong\n");
			}	
			}while(strcmp(logAdmin.Email,checkEmail) !=0 && strcmp(logAdmin.Password,checkPass) != 0);//while
}

void MenuBook(){//Hien thi menu danh sach
			printf("\n------------------------MENU------------------------\n");
			printf("1. Hien thi so danh sach dang quan ly \n");//hien thi Book dang quan ly
			printf("2. Them Book vao danh sach\n");//Them Book vao danh sach
			printf("3. Sua thong tin sach\n  ");
			//Sua sach (khong sua ID)
			printf("4. ");
}

void Book_01(int *Count, int *number, Book Books[100]){//Hien thi Book dang quan ly
			printf("Lua chon cua ban la: 1 In thong tin sach\n");
			printf("\n");
			printf("Danh sach Book dang quan ly la: \n"); 
			printf("\t******************************************\n");
		    printf("\t*************** Book List ****************\n");
		    printf("\t******************************************\n");
		    printf("|============|===========================|======================|============|\n");
		    printf("|   BookID   |         Ten Sach          |     Ten Tac Gia      |  Gia Tien  |\n");
		    printf("|============|===========================|======================|============|\n");
    for (int i = 0; i < *number; i++) {
	    	Books[*Count].ID = *Count +1;
	   		printf("| %-10d | %-25s | %-20s | %-10.3lf |\n",
            Books[i].ID, 
            Books[i].Name, 
            Books[i].Author, 
            Books[i].Price);
    }
			printf("|------------|---------------------------|----------------------|------------|\n");
}

void Book_02(int *Count,int *temp,int *number, Book Books[100]){//Them Book
			printf("Lua chon cua ban la: 2 Them Book vao danh sach");
			printf("\n");
			printf("Nhap so luong can them la: ");
			scanf("%d", temp);
		for(int i=0;i<*temp;i++){
			Books[*number].ID = *number +1;
			printf("ID: %d\n",Books[*number].ID);
			fflush(stdin);
			printf("Moi ban nhap ten sach: ");
			fgets(Books[*number].Name,sizeof(Books[*number].Name),stdin);
			Books[*number].Name[strcspn(Books[*number].Name, "\n")] = '\0';
			printf("Moi ban nhap ten tac gia: ");
			fgets(Books[*number].Author,sizeof(Books[*number].Author),stdin);
			Books[*number].Author[strcspn(Books[*number].Author, "\n")] = '\0';
			printf("Moi ban nhap gia tien: ");
			scanf("%lf",&Books[*number].Price);
			(*number)++;
	}
}

int Book_03(int *temp,int *number, Book Books[100]){//Sua thong tin sach
			printf("Lua chon cua ban la: 3 Sua thong tin Book");
			printf("\n");
			printf("Nhap ID muon sua la: (0-%d)",*number -1);
			scanf("%d",temp);
			if(*temp >*number || *temp <0){
			printf("ID BAN CAN SUA KHONG HOP LE\n");
			printf("\n");
			return 1;
	}else{
			fflush(stdin);
			Books[*temp].ID = *temp +1;
			printf("ID: %d\n",Books[*temp].ID);
			printf("Moi ban nhap ten sach: ");
			fgets(Books[*temp].Name,sizeof(Books[*temp].Name),stdin);
			Books[*temp].Name[strcspn(Books[*temp].Name, "\n")] = '\0';
			printf("Moi ban nhap ten tac gia: ");
			fgets(Books[*temp].Author,sizeof(Books[*temp].Author),stdin);
			Books[*temp].Author[strcspn(Books[*temp].Author, "\n")] = '\0';
			printf("Moi ban nhap gia tien: ");
			scanf("%lf",&Books[*temp].Price);
			printf("BAN DA SUA THANH CONG\n");
			printf("\n");
	}
}
int Book_04(int *temp, int *number, Book Books[100]){//Xoa thong tin Book
			int n;//Lua chon xoa hoac khong
			printf("Lua chon cua ban la 4 Xoa thong tin sach\n");
			printf("\n");
			printf("Moi ban nhap vi tri can xoa la: (0-%d) ",*number -1);
			scanf("%d",temp);
			if(*temp > *number || *temp <0){
					printf("ID can xoa khong hop le\n");
					return 1;
			}else{
					printf("XOA (a) or THOAT (b) ");
					scanf("%d",&n);
					if(n == 1){//XOA
					for(int i=*number;i>*temp;i++){
					Books[*number-1] = Books[*number];
					}
					(*number)--;	
					}else if(n == 0){//KHONG XOA
					MenuBook();
					}else{
						printf("Lua chon cua ban khong hop le\n");
					}
			}

}

