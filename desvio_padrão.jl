function desvio_padrao_amostral(y)
    media=sum(y)/length(y)
    return sqrt(sum((y.-media).^2)/(length(y)-1))
end

function desvio_padrao(y)
    media=sum(y)/length(y)
    return sqrt(sum((y.-media).^2)/(length(y)))
end