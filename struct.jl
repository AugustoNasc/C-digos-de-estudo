abstract type Polinomio end

struct Linear <: Polinomio
    a::Number # coef. de x.
    b::Number # coef. linear.
    # default constructor - membros em sequência
end

#multiple dispatch - independe das heranças.
poly_string(l::Linear) = "$(l.a) x + $(l.b)"
solve(l::Linear) = [-l.b / l.a]


struct SecondDegree <: Polinomio
    a::Number # coef. de x^2.
    b::Number # coef. de x.
    c::Number # coef. independente.
    function SecondDegree(a, b, c) # inner constructor - validação interna.
        if isapprox(a, 0)
            error("o que você acha que está fazendo 🤨?")
        end
        new(a, b, c)
    end
end

function SecondDegree(l1::Linear, l2::Linear) # outer constructor - escolhidos com multiple dispatch.
    SecondDegree(l1.a * l2.a, l1.a * l2.b + l1.b * l2.a, l1.b * l2.b)
end

poly_string(sd::SecondDegree) = "$(sd.a) x² + $(sd.b) x + $(sd.c)"

function solve(sd::SecondDegree)
    delta = sd.b^2 - 4 * sd.a * sd.c
    if delta < 0
        -sd.b / (2 * sd.a) .+ √complex(delta) / (2 * sd.a) * [-1, 1]
    else
        -sd.b / (2 * sd.a) .+ √delta / (2 * sd.a) * [-1, 1]
    end
end

#herança
function pretty_print_poly(ap::Polinomio)
    "O polinômio " * poly_string(ap) * " tem raizes = " * join(string.(solve(ap)), ", ")
end