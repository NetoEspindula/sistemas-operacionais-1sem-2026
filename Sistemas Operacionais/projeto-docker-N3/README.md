# Trabalho N3 - Sistemas Operacionais

Aluno: Valdemar Espindula Neto

Disciplina: Sistemas Operacionais

Neste trabalho eu montei uma infraestrutura com Docker contendo uma aplicacao web
em Node.js (usando o Express) e um banco de dados MySQL. Tambem criei uma rede
propria, um volume pra guardar os dados, coloquei limite de memoria e fiz a
aplicacao rodar com um usuario que nao e root.

## Estrutura do projeto

```
projeto-docker/
├── docker-compose.yml
├── app/
│   ├── Dockerfile
│   ├── package.json
│   └── server.js
├── evidencias/
│   ├── docker-ps.txt
│   ├── docker-stats.txt
│   ├── docker-inspect-app.txt
│   ├── logs-app.txt
│   ├── print-navegador.png
│   └── print-pid.png
└── README.md
```

## Como rodar

Dentro da pasta projeto-docker eu rodei:

```
docker compose up -d --build
```

Depois acessei no navegador:

- http://localhost:3000/ (rota principal)
- http://localhost:3000/info (rota do desafio)


```json
{
  "disciplina": "Sistemas Operacionais",
  "aluno": "Valdemar Espindula Neto",
  "hostname": "5c992dda8148",
  "plataforma": "linux",
  "arquitetura": "x64"
}
```



```json
{
  "pid": 1,
  "uptime": 8,
  "cpus": 20
}
```

## Respostas das perguntas

### 1. Qual a diferenca entre imagem e container?
A imagem e o modelo, ela so e leitura e tem tudo que o programa precisa pra rodar.
O container e quando essa imagem esta rodando de verdade. De uma imagem da pra criar varios containers.

### 2. Qual processo esta executando dentro do container?
E o Node rodando o arquivo server.js (o comando node server.js). Ele e o processo
principal e fica como PID 1 dentro do container.

### 3. O container possui kernel proprio? Justifique.
Nao. O container usa o mesmo kernel da maquina. O Docker so separa os
processos usando recursos do proprio Linux (namespaces e cgroups), mas nao tem um
kernel separado. Por isso ele e mais leve que uma maquina virtual.

### 4. Qual recurso foi limitado na sua infraestrutura?
Eu limitei a memoria em 128 MB no servico app, usando o mem_limit: 128m no
docker-compose. 

### 5. Qual a finalidade do volume Docker utilizado?
O volume serve pra guardar os dados do MySQL na pasta /var/lib/mysql. Assim, mesmo
se eu apagar o container e criar de novo, os dados continuam salvos.

### 6. Qual a finalidade da rede Docker criada?
A rede serve pra os containers conversarem entre si pelo nome. O app consegue achar
o banco pelo nome db. E so a porta 3000 fica aberta pra fora, o banco fica protegido.

### 7. Por que executar aplicacoes como usuario nao-root?
Por seguranca. Se alguem invadir a aplicacao, um usuario que nao e root tem menos
poder, entao o estrago fica menor. Por isso eu rodei com o usuario node.

### 8. Por que Docker nao e uma maquina virtual?
A maquina virtual roda um sistema operacional inteiro com kernel proprio e e pesada.
O Docker so compartilha o kernel da maquina e separa os processos, entao ele e bem
mais leve e rapido pra ligar.

### 9. O que representa o PID exibido na rota /info?
E o numero do processo do Node dentro do container. Como o node e o primeiro programa
a iniciar, ele fica com o PID 1.

### 10. Cite tres conceitos de Sistemas Operacionais presentes neste projeto.
1. Processos (PID, uptime e o processo PID 1).
2. Gerenciamento de recursos (limite de memoria de 128 MB).
3. Sistema de arquivos (volume do Docker guardando os dados do banco).
Tambem tem redes, virtualizacao e seguranca (usuario nao-root).
