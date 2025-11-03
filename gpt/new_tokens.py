token_memory = {}

def generate_token(word):
    return sum(ord(c) for c in word)

def learn_word(word):
    token = generate_token(word)
    token_memory[word] = token
    with open("memory.txt", "a") as f:
        f.write(f"{word}:{token}\n")
    print(f"Aprendi: {word} -> Token: {token}")

print("LumaGPT (Python) pronto! Digite palavras:")

while True:
    inp = input("> ")
    if inp.lower() == "sair":
        break
    learn_word(inp)
