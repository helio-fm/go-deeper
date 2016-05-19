/*
  ==============================================================================

    XMLSerializer.h
    Created: 17 Sep 2015 11:51:04am
    Author:  Peter Rudenko

  ==============================================================================
*/

#ifndef XMLSERIALIZER_H_INCLUDED
#define XMLSERIALIZER_H_INCLUDED

// The PugiXML-based serializer
#include "pugixml.hpp"

class PugiXMLSerializer final : public TinyRNN::Serializer
{
public:
    
    PugiXMLSerializer() {}
    ~PugiXMLSerializer() override {}
    
    class Context final : public TinyRNN::SerializationContext
    {
    public:
        
        using Ptr = std::shared_ptr<Context>;
        
    public:
        
        explicit Context(pugi::xml_node rootNode) : node(rootNode) {}
        
        virtual void setRealProperty(TinyRNN::Value value, const std::string &key) override
        { this->node.append_attribute(key.c_str()).set_value(value); }
        
        virtual TinyRNN::Value getRealProperty(const std::string &key) const override
        { return this->node.attribute(key.c_str()).as_double(); }
        
        virtual void setNumberProperty(long long value, const std::string &key) override
        { this->node.append_attribute(key.c_str()).set_value(value); }
        
        virtual long long getNumberProperty(const std::string &key) const override
        { return this->node.attribute(key.c_str()).as_llong(); }
        
        virtual void setStringProperty(const std::string &value, const std::string &key) override
        { this->node.append_attribute(key.c_str()).set_value(value.c_str()); }
        
        virtual std::string getStringProperty(const std::string &key) const override
        { return std::string(this->node.attribute(key.c_str()).as_string()); }
        
        virtual size_t getNumChildrenContexts() const override
        { return std::distance(this->node.children().begin(), this->node.children().end()); }
        
        virtual SerializationContext::Ptr getChildContext(int index) const override
        {
            pugi::xml_node child = *std::next(this->node.children().begin(), index);
            Context::Ptr childContext(new Context(child));
            return childContext;
        }
        
        virtual SerializationContext::Ptr getChildContext(const std::string &key) const override
        {
            pugi::xml_node child = node.child(key.c_str());
            Context::Ptr childContext(new Context(child));
            return childContext;
        }
        
        virtual SerializationContext::Ptr addChildContext(const std::string &key) override
        {
            pugi::xml_node newChild = node.append_child(key.c_str());
            Context::Ptr childContext(new Context(newChild));
            return childContext;
        }
        
        virtual SerializationContext::Ptr addChildContextUnordered(const std::string &key) override
        {
            pugi::xml_node newChild = node.append_child(key.c_str());
            Context::Ptr childContext(new Context(newChild));
            return childContext;
        }
        
    private:
        
        pugi::xml_node node;
        
    };

    
    virtual std::string serialize(TinyRNN::SerializedObject::Ptr target, const std::string rootNodeName) const override
    {
        const TinyRNN::ScopedTimer timer("XMLSerializer::serialize");
        
        pugi::xml_document document;
        Context::Ptr root(new Context(document.root()));
        TinyRNN::SerializationContext::Ptr mainContext(root->addChildContext(rootNodeName));
        
        target->serialize(mainContext);
        
        XMLStringWriter writer;
        document.save(writer);
        return writer.result;
    }
    
    virtual void deserialize(TinyRNN::SerializedObject::Ptr target, const std::string &data) override
    {
        const TinyRNN::ScopedTimer timer("XMLSerializer::deserialize");
        
        pugi::xml_document document;
        pugi::xml_parse_result result = document.load(data.c_str());
        
        if (result)
        {
            Context::Ptr root(new Context(document.root()));
            TinyRNN::SerializationContext::Ptr mainContext(root->getChildContext(0));
            target->deserialize(mainContext);
        }
    }
    
private:
    
    struct XMLStringWriter: pugi::xml_writer
    {
        std::string result;
        
        virtual void write(const void *data, size_t size) override
        {
            result.append(static_cast<const char*>(data), size);
        }
    };
    
};

#endif  // XMLSERIALIZER_H_INCLUDED
