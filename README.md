# Philosophers

Este projeto é parte do currículo da 42 Luanda e tem como objetivo simular o problema dos filósofos comensais, um clássico problema de sincronização em computação.

## Objetivo

O objetivo principal é implementar uma solução para o problema dos filósofos comensais utilizando threads e mecanismos de sincronização para evitar condições de corrida e deadlocks.

## Descrição

O problema dos filósofos comensais envolve cinco filósofos que passam o tempo pensando e comendo. Eles se sentam em uma mesa redonda com um prato de espaguete e um garfo entre cada par de filósofos. Para comer, um filósofo precisa pegar os dois garfos adjacentes a ele. O desafio é garantir que os filósofos possam comer sem causar um deadlock.

## Requisitos

- Implementar a solução em C.
- Utilizar threads para representar cada filósofo.
- Utilizar mutexes ou semáforos para gerenciar o acesso aos garfos.
- Evitar condições de corrida e deadlocks.

## Como Compilar

Para compilar o projeto, utilize o comando:

```sh
gcc -o philosophers philosophers.c -lpthread
```

## Como Executar

Para executar o projeto, utilize o comando:

```sh
./philosophers
```

## Estrutura do Projeto

- `philosophers.c`: Arquivo principal com a implementação do problema dos filósofos comensais.
- `README.md`: Este arquivo, contendo a descrição do projeto.

## Referências

- [Problema dos Filósofos Comensais - Wikipedia](https://pt.wikipedia.org/wiki/Problema_dos_fil%C3%B3sofos_comensais)
- [Documentação da Biblioteca Pthread](https://man7.org/linux/man-pages/man7/pthreads.7.html)

## Autores

- Nome do Autor 1
- Nome do Autor 2
