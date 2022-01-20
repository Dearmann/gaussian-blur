.data
matrix: ;tablica wag rozkladu gaussa
word 1
word 1
word 1
word 2
word 2
word 2
word 1
word 1
word 1
word 2
word 2
word 2
word 4
word 4
word 4
word 2
word 2
word 2
word 1
word 1
word 1
word 2
word 2
word 2
word 1
word 1
word 1

.code
_DllMainCRTStartup PROC 
mov rax, 1 
ret
_DllMainCRTStartup ENDP

;funkcja rozmywajaca obraz za pomoca algorytmu gaussa
;parametry: wskaznik na dane bitmapy (rcx), rozmiar bitmapy (rdx), szerokosc bitmapy (r8),
;wartosc poczatku wykonywania rozmycia (r9), wartosc konca rozmycia (stack)
gaussianBlur proc

;pobranie wag z macierzy
movdqu xmm0, oword ptr[matrix]
movdqu xmm1, oword ptr[matrix + 6]
movdqu xmm2, oword ptr[matrix + 12]
movdqu xmm3, oword ptr[matrix + 18]
movdqu xmm4, oword ptr[matrix + 24]
movdqu xmm5, oword ptr[matrix + 30]

xor r10, r10
mov r10d, dword ptr[rbp+48] ;przeniesienie ze stosu numeru wiersza zatrzymania algorytmu
mov r15, rcx ;poczatek bitmapy
mov rax, r8 ;szerokosc bitmapy do akumulatora
imul rax, 3 ;pomnozenie bitmapy x3 - rozdzielenie pikseli na ich skladowe RGB
mov rdi, rax ;rdi - szerokosc skladowych pikseli
imul rax, r9 ;szerokosc skladowych * poczatkowy wiersz -> miejsce rozpoczecia algorytmu
mov rcx, rax ;rcx - poczatek algorytmu, licznik petli
mov rax, rdi 
imul rax, r10 ;szerokosc skladowych * koncowy wiersz -> miejsce zakonczenia algorytmu
mov r12, rax ;r12 - koniec algorytmu

;sprawszenie czy lewy gorny piksel siatki nie jest poza tablica
loop1:
add rcx, 3 ;inkrementacja licznika o 3
mov rax, rcx
sub rax, rdi ;przejscie o rzad wyzej w bitmapie
sub rax, 3 ;przejscie o 1 piksel w lewo
cmp rax, 0
jl loop1

;sprawdzenie czy prawy dolny piksel siatki nie jest poza tablica
mov rax, rcx
add rax, rdi ;przejscie o rzad nizej w bitmapie
add rax, 3 ;przejscie o 1 piksel w prawo
cmp rax, rdx ;czy wartosc akumulatora jest wieksza od bitmapy
jae endBlur ;jesli tak - zakoncz algorytm

;pobranie wartosci skladowych siatki 9 pikseli do rejestrow xmm6-xmm14
mov rax, r15
add rax, rcx ;dodanie licznika do poczatku bitmapy
sub rax, rdi ;przejscie o rzad wyzej w bitmapie
sub rax, 3 ;rax - lewy gorny piksel siatki
pmovzxbw xmm6, [rax] ;przeniesienie 8 skladowych pixeli
add rax, 3 ;przejscie o 1 piksel w prawo
pmovzxbw xmm7, [rax]
add rax, 3
pmovzxbw xmm8, [rax]
add rax, rdi ;przejscie o rzad nizej w bitmapie
pmovzxbw xmm9, [rax]
sub rax, 3
pmovzxbw xmm10, [rax]
sub rax, 3
pmovzxbw xmm11, [rax]
add rax, rdi
pmovzxbw xmm12, [rax]
add rax, 3
pmovzxbw xmm13, [rax]
add rax, 3
pmovzxbw xmm14, [rax]

;przemnozenie wartosci pixeli przez odpowiednie wagi
pmullw xmm6, xmm0
pmullw xmm7, xmm1
pmullw xmm8, xmm2
pmullw xmm9, xmm3
pmullw xmm10, xmm4
pmullw xmm11, xmm5
pmullw xmm12, xmm0
pmullw xmm13, xmm1
pmullw xmm14, xmm2

;zsumowanie pixeli
paddw xmm6, xmm7
paddw xmm6, xmm8
paddw xmm6, xmm9
paddw xmm6, xmm10
paddw xmm6, xmm11
paddw xmm6, xmm12
paddw xmm6, xmm13
paddw xmm6, xmm14

psrlw xmm6, 4 ;podzielenie przez sume wag
pextrw r9, xmm6, 0 ;skladowa red piksela wynikowego do rejestru r9
pextrw r13, xmm6, 1 ;skladowa green piksela wynikowego do rejestru r13
pextrw r14, xmm6, 2 ;skladowa blue piksela wynikowego do rejestru r14

mov r11, r15 ;poczatek bitmapy do rejestru r11
add r11, rcx ;poczatek bitmapy + licznik -> srodek siatki

;modyfikacja wartosci skladowych piksela
mov byte ptr[r11], r9b
add r11, 1
mov byte ptr[r11], r13b
add r11, 1
mov byte ptr[r11], r14b


cmp rcx, r12 ;sprawdz czy licznik osiagnal punkt koncowy algorytmu
jae endBlur
jmp loop1

endBlur:
ret

gaussianBlur endp
end