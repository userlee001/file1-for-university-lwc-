#include<bits/stdc++.h>
#include <windows.h>
using namespace std ;
void fx( map<int,string>mpi1 , map<int,string>mpipla1 , int arr11[7] ){
	cout << "���� : " ;
	bool chpla1 = false ;
	for( int i=1 ; i<=6 ; i++ ){
        if( arr11[i] != 0 ){
            if( i == 1 || i == 6){
        	    cout << mpi1[i] << mpipla1[arr11[i]] << " " ;
			}else{
				cout << mpipla1[arr11[i]] << mpi1[i] << " " ; 
		    }
		    chpla1 = true ; 
        }	
	}
	if( chpla1 == false ){
        cout << "�L " ; 
    }
} // �P�_����  
int main(){
	srand( time(NULL) ) ;
    cout << "�а�X�A���W�r" << endl ;
	cout << "�а�X�A�Q�ݪ��O" << endl ;
	int x,y,z ; // �@���T�T ;
	int h1,h2,h3 ; //�������� �A +1�� �A -1�� ;
	int upb = 0 , downb = 0 ; //upb�����W��,downb�����U�� ; // 1�� , 2�� ;
	int upa = 0 , downa = 0 ; //upa�ܨ��W��,downa�ܨ��U�� ; // 1�� , 2�� ;  
	int arr1[7] ; // �ѳ�6 , �Ѷ�9 , ��l0 ; 
	int n ; 
	map<int,string>mp ; // ������ ;
	map<int,string>mpi ; // ���� ; 
	map<int,string>mpipla ; // ���� ; 
	mp[111] = "��" ; mp[112] = "�I" ; mp[121] = "��" ; mp[122] = "�_" ; mp[211] = "�S" ; mp[212] = "��" ; mp[221] = "��" ; mp[222] = "�[" ;
	mpi[1] = "��" ; mpi[2] = "�G" ; mpi[3] = "�T" ; mpi[4] = "�|" ; mpi[5] = "��" ; mpi[6] = "�W" ; 
	mpipla[6] = "��"  ; mpipla[9] = "�E" ; 
	arr1[0] = 0 ;
	bool ch , chpla ; // �ˬd�O�_�������� ; // �ˬd���L���� ;  
	for( int i=1 ; i<=6 ; i++ ){
		cout << "�Х�ɪO(��J1)" << endl ;
		cin >> n ;
		if( n!=1 ){
			abort() ;
		}
		cout << mpi[i] << " : " ; 
		x = rand() ; // �_�ƬO�� �A ���ƬO�� ; 
		y = rand() ;
		z = rand() ;
		if( x%2 == 0){
			h1 = -1 ;
		}else{
			h1 = 1 ;
		}
		if( y%2 == 0){
			h2 = -1 ;
		}else{
			h2 = 1 ;
		}
		if( z%2 == 0){
			h3 = -1 ;
		}else{
			h3 = 1 ;
		}
		if( h1 + h2 + h3 == 3 ){
			arr1[i] = 9 ;
			cout << "�Ѷ�" << endl ; 
		}else if( h1 + h2 + h3 == -3 ){
			arr1[i] = 6 ;
			cout << "�ѳ�" << endl ; 
		}else{
			arr1[i] = 0 ;
			if( h1 + h2 + h3 == 1 ){
			    cout << "�ֶ�" << endl ; 
		    }
		    if( h1 + h2 + h3 == -1 ){
			    cout << "�ֳ�" << endl ; 
		    }
		} // �Y�w���A��ܨC�����Y���G 
		if( i<=3 && h1*h2*h3 == 1 ){
			downb = downb*10 + 1 ;
			if( arr1[i] != 0 ){
				downa = downa*10 + 2 ;
			}else{
				downa = downa*10 + 1 ;
			}
		}
		if( i<=3 && h1*h2*h3 == -1 ){
			downb = downb*10 + 2 ;
			if( arr1[i] != 0 ){
				downa = downa*10 + 1 ;
			}else{
				downa = downa*10 + 2 ;
			}
		}
		if( i>3 && h1*h2*h3 == 1 ){
			upb = upb*10 + 1 ;
			if( arr1[i] != 0 ){
				upa = upa*10 + 2 ;
			}else{
				upa = upa*10 + 1 ;
			}
		}
		if( i>3 && h1*h2*h3 == -1 ){
			upb = upb*10 + 2 ;
			if( arr1[i] !=0 ){
				upa = upa*10 + 1 ;
			}else{
				upa = upa*10 + 2 ;
			}
		}
	} // �M�w���H 
	if( upb == downb ){
		cout << "���� : " << mp[upb] << "��" << endl ;
		if( upb == 111 || upb == 222 ){ // ��  || �[ ;  
			ch = false ; 
	        for( int i=1 ; i<=6 ; i++ ){
                if( arr1[i] == 0 ){
        	        ch = true ;
        	        break ;
		        }	
	        }
	        if( ch == false && upb == 111 ){
	        	cout << "���� : �ΤE" << endl ;
			}else if( ch == false && upb == 222 ){
	        	cout << "���� : �Τ�" << endl ;
			}else{
				fx( mpi , mpipla , arr1 ) ;
			}
		}else{
		    fx( mpi , mpipla , arr1 ) ;
	    }
	}else{ 
	    cout << "���� : " << mp[upb] << "��" << mp[downb] << endl ;
	    fx( mpi , mpipla , arr1 ) ;   
	}
	cout << endl ;
	for( int i=1 ; i<7 ; i++ ){
		if( arr1[i] == 9 ){
			arr1[i] = 6 ; 
		}else if(arr1[i] == 6){
		    arr1[i] = 9 ;
	    }
	}
	if( upa == downa ){
		cout << "���� : " << mp[upa] << "��" << endl ;
		if( upa == 111 || upa == 222 ){ // ��  || �[ ;  
			ch = false ; 
	        for( int i=1 ; i<=6 ; i++ ){
                if( arr1[i] == 0 ){
        	        ch = true ;
        	        break ;
		        }	
	        }
	        if( ch == false && upa == 111 ){
	        	cout << "���� : �ΤE" << endl ;
			}else if( ch == false && upa == 222 ){
	        	cout << "���� : �Τ�" << endl ;
			}else{
				fx( mpi , mpipla , arr1 ) ;
			}
		}
	}else{ 
	    cout << "���� : " << mp[upa] << "��" << mp[downa] << endl ;
	    fx( mpi , mpipla , arr1 ) ;   
	} // ��X�̲׵��G(���H+����)  
	cout << endl ;
	cout << "���H�P���㪺�����аѦҩ��Ǻ�(https://www.eee-learning.com/)" << endl ; 
	Sleep(180000) ;
}
