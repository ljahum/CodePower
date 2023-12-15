
def func(text: str):
        
    text = text.replace('&quot;', '"')
    text = text.replace('&apos;', "'")
    text = text.replace('&gt;', '>')
    text = text.replace('&lt;', '<')
    text = text.replace('&frasl;', '/')
    text = text.replace('&amp;', '&')
    
    return text


            
text = "&amp; is an HTML entity but &ambassador; is not."
text = "and I quote: &quot;...&quot;"
text_ = func(text)
print(text_)