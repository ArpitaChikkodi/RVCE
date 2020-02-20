import couchdb
couch = couchdb.Server()

couch = couchdb.Server('http://example.com:5984/')
db = couch.create('test')
doc = {'foo': 'bar'}
db.save(doc)
doc

db.delete(doc)
couch.delete('test')
