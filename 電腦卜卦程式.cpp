#include<bits/stdc++.h>
#include <windows.h>
using namespace std ;
void fx( map<int,string>mpi1 , map<int,string>mpipla1 , int arr11[7] ){
	cout << "爻辭 : " ;
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
        cout << "無 " ; 
    }
} // 判斷爻辭  
int main(){
	srand( time(NULL) ) ;
    cout << "請唸出你的名字" << endl ;
	cout << "請唸出你想問的是" << endl ;
	int x,y,z ; // 一次三枚 ;
	int h1,h2,h3 ; //紀錄陰陽 ， +1陽 ， -1陰 ;
	int upb = 0 , downb = 0 ; //upb本卦上卦,downb本卦下卦 ; // 1陽 , 2陰 ;
	int upa = 0 , downa = 0 ; //upa變卦上卦,downa變卦下卦 ; // 1陽 , 2陰 ;  
	int arr1[7] ; // 老陰6 , 老陽9 , 其餘0 ; 
	int n ; 
	map<int,string>mp ; // 對應卦 ;
	map<int,string>mpi ; // 爻位 ; 
	map<int,string>mpipla ; // 陰陽 ; 
	mp[111] = "乾" ; mp[112] = "兌" ; mp[121] = "離" ; mp[122] = "震" ; mp[211] = "巽" ; mp[212] = "坎" ; mp[221] = "艮" ; mp[222] = "坤" ;
	mpi[1] = "初" ; mpi[2] = "二" ; mpi[3] = "三" ; mpi[4] = "四" ; mpi[5] = "五" ; mpi[6] = "上" ; 
	mpipla[6] = "六"  ; mpipla[9] = "九" ; 
	arr1[0] = 0 ;
	bool ch , chpla ; // 檢查是否有六爻變 ; // 檢查有無爻變 ;  
	for( int i=1 ; i<=6 ; i++ ){
		cout << "請丟銅板(輸入1)" << endl ;
		cin >> n ;
		if( n!=1 ){
			abort() ;
		}
		cout << mpi[i] << " : " ; 
		x = rand() ; // 奇數是陽 ， 偶數是陰 ; 
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
			cout << "老陽" << endl ; 
		}else if( h1 + h2 + h3 == -3 ){
			arr1[i] = 6 ;
			cout << "老陰" << endl ; 
		}else{
			arr1[i] = 0 ;
			if( h1 + h2 + h3 == 1 ){
			    cout << "少陽" << endl ; 
		    }
		    if( h1 + h2 + h3 == -1 ){
			    cout << "少陰" << endl ; 
		    }
		} // 擲硬幣，顯示每次丟擲結果 
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
	} // 決定卦象 
	if( upb == downb ){
		cout << "本卦 : " << mp[upb] << "卦" << endl ;
		if( upb == 111 || upb == 222 ){ // 乾  || 坤 ;  
			ch = false ; 
	        for( int i=1 ; i<=6 ; i++ ){
                if( arr1[i] == 0 ){
        	        ch = true ;
        	        break ;
		        }	
	        }
	        if( ch == false && upb == 111 ){
	        	cout << "爻辭 : 用九" << endl ;
			}else if( ch == false && upb == 222 ){
	        	cout << "爻辭 : 用六" << endl ;
			}else{
				fx( mpi , mpipla , arr1 ) ;
			}
		}else{
		    fx( mpi , mpipla , arr1 ) ;
	    }
	}else{ 
	    cout << "本卦 : " << mp[upb] << "之" << mp[downb] << endl ;
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
		cout << "之卦 : " << mp[upa] << "卦" << endl ;
		if( upa == 111 || upa == 222 ){ // 乾  || 坤 ;  
			ch = false ; 
	        for( int i=1 ; i<=6 ; i++ ){
                if( arr1[i] == 0 ){
        	        ch = true ;
        	        break ;
		        }	
	        }
	        if( ch == false && upa == 111 ){
	        	cout << "爻辭 : 用九" << endl ;
			}else if( ch == false && upa == 222 ){
	        	cout << "爻辭 : 用六" << endl ;
			}else{
				fx( mpi , mpipla , arr1 ) ;
			}
		}
	}else{ 
	    cout << "之卦 : " << mp[upa] << "之" << mp[downa] << endl ;
	    fx( mpi , mpipla , arr1 ) ;   
	} // 輸出最終結果(卦象+爻位)  
	cout << endl ;
	cout << "卦象與爻辭的解釋請參考易學網(https://www.eee-learning.com/)" << endl ; 
	Sleep(180000) ;
}
