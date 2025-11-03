token_memory = Dict{String, Int}()

function generate_token(word::String)
    sum(Int(c) for c in word)
end

function learn_word(word::String)
    token = generate_token(word)
    token_memory[word] = token
    open("memory.txt", "a") do f
        write(f, "$word:$token\n")
    end
    println("Aprendi: $word -> Token: $token")
end

println("LumaGPT (Julia) pronto! Digite palavras:")

while true
    print("> ")
    input = readline()
    if lowercase(input) == "sair"
        break
    end
    learn_word(input)
end
