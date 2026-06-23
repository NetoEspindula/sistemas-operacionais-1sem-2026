# imagem base do node 
FROM node:20-alpine

# pasta onde a aplicacao vai ficar dentro do container
WORKDIR /usr/src/app

# copia o package.json primeiro
COPY package*.json ./

# instala as dependencias
RUN npm install --omit=dev

# copia o resto dos arquivos
COPY . .

# o usuario "node" ja vem na imagem, entao deixo ele como dono dos arquivos
# e troco pra ele pra nao rodar como root
RUN chown -R node:node /usr/src/app
USER node

# porta que a aplicacao usa
EXPOSE 3000

# comando que inicia a aplicacao
CMD ["node", "server.js"]
