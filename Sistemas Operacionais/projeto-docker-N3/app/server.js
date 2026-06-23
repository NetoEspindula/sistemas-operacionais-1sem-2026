// importando o express pra criar o servidor
const express = require("express");
// modulo os do node, ele pega infos do sistema 
const os = require("os");

const app = express();

// porta que o servidor vai usar
const PORT = process.env.PORT || 3000;

// pega meu nome de uma variavel de ambiente
const ALUNO = process.env.ALUNO || "Valdemar Espindula Neto";

// rota principal "/"
app.get("/", (req, res) => {
  res.json({
    disciplina: "Sistemas Operacionais",
    aluno: ALUNO,
    hostname: os.hostname(), // id do container
    plataforma: os.platform(), // linux
    arquitetura: os.arch() // x64
  });
});

// rota /info pedida no desafio
app.get("/info", (req, res) => {
  res.json({
    pid: process.pid, // numero do processo
    uptime: Math.floor(process.uptime()), // tempo ligado em segundos
    cpus: os.cpus().length // quantidade de cpus
  });
});

// liga o servidor
app.listen(PORT, () => {
  console.log("Servidor rodando na porta " + PORT);
  console.log("Aluno: " + ALUNO);
});
