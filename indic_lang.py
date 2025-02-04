from inltk.inltk import get_embedding_vectors
from warnings import filterwarnings
from IPython.display import display
filterwarnings("ignore")

text = 'മലയലത്തിന്റെ ഉത്ഭവം തർക്കവിഷയമായി തുടരുന്നു'
vectors = get_embedding_vectors(text, 'ml')
display(vectors)

# import fasttext
# import fasttext.util
# ft = fasttext.load_model('wiki.hi.bin')
# word = "नृत्य"
# print("Embedding Shape is {}".format(ft.get_word_vector(word).shape))
# print("Nearest Neighbors to {} are:".format(word))
# ft.get_nearest_neighbors(word) 