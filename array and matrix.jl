x=[3,4,1,1,2,8,7,5,9]
y=sort(x) #ordenando invertidamente
show(y)# [9 8 7 5, 4, 3, 2, 1, 1]

A=[4 3; 1 2]
sort!(A) #sort!() muda o próprio vetor
sort!(A, dims=1) #odenar apenas entre colunas, caso dims=1, ordenariamos as linhas
sort!(A, rev=true)#ordem decrescente
sort!(A, by=abs)#by=f aplica uma função f nos elementos antes de comparar

# Terceiro bloco: vetores, matrizes, indexação, slicing e etc

A = [4 3 1; 5 7 0] # matriz 2 x 3: o caractere ';' termina uma linha.
show(A[1, 2]) # uma forma de acessar o elemento na posição (1, 2), ou seja, 3
display(A[3]) # outra forma de acessar a posicao (1, 2)
display(A[:, 2]) # todos os elementos da coluna 2.
display(A[1, :]) # todos os elementos da linha 1. note que sempre retorna um vetor.
display(A[1:2, 2:3]) # slicing.

A = rand(6, 6) # note que até aqui, A não havia sido alterada.
display(A[begin:2:end, :]) # retorna todos os elementos das linhas 1, 3, 5 com todas as colunas.
display(A[begin:2:end, 2:3:end]) # retorna todos os elementos das linhas 1, 3, 5 com as colunas 2 e 5.
display(A[A .> 0.6]) # retorna um vetor com todos os elementos de A que são maiores que 0.6.
display(A[0.2 .< A .< 0.7]) # veja que as comparações podem ser colocadas juntas.
A[A .< 0.6] .= 0 # transforma em zero todos os elementos de A que forem menores que 0.6. retorna um vetor da função "view" com esses índices.

display(sin.(1:4:14)) # retorna um vetor [sin(1), sin(5), sin(9), sin(13)]