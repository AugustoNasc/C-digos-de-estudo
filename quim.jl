Na=6.0221408e+23
h=6.62607015e-34
Ctil=300e8
c=3e+8
carga = 1.602e-19
# kBoltz=1.380649e-23
kBoltz = 8.62e-5

#fórmulas relativas ao conteudo de espectroscopia rotacional/vibracional
#e também de cristalografia

function R(m1, m2, B)
    return sqrt(h/(8*(π^2)*B*Ctil*μ(m1,m2)))
    end

function μ(m1,m2)
    return (m1*m2/(m1+m2))/(Na*10^3)
    end

function B(m1, m2, R)
    return h/(8*(π^2)*Ctil*μ(m1, m2)*(R^2))
    end

function B(m1inicio, m2inicio, m1fim, m2fim, Binicio)
    return (μ(m1inicio, m2inicio)/μ(m1fim,m2fim))*Binicio
    end

function I(B)
    return h/(8*(π^2)*Ctil*B)
    end

function k(m1, m2, v)
    return ((v*100*2*π)^2)*μ(m1,m2)
    end

function ve(k, m1, m2)
    return (1/(2*π))*sqrt((k/μ(m1,m2)))
    end

function a(λ, θ, h, k, l)
    return (λ/(2*sind(θ)))*sqrt(h^2+k^2+l^2)
    end

function densidade(n, MM, a)
    return n*MM/(Na*a^3)
    end

function razao(teta1, teta2)
    return sind(teta1)^2/sind(teta2)^2
    end

function a(d, h, k, l)
    return d*sqrt(h^2+k^2+l^2)
    end

function d(λ, teta)
    return λ/(2*sind(teta))
    end

function n(densidade, a, M)
    return densidade*(a^3)*Na/M
    end

function N(densidade, M)
    return (densidade*Na/M)*10^6
    end

function numeroAtomos(R, a, b, c, FE)
    return FE*a*b*c*3/(4*π*R^3)
    end
