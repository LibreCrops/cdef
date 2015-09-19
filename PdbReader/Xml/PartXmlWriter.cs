using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Xml
{
    class PartXmlWriter
    {
        private class Frame
        {
            private string _tag;
            private bool _hasChild;
            public Frame(string tag)
            {
                _tag = tag;
                _hasChild = false;
            }
            public string Tag
            {
                get { return _tag; }
            }
            public bool HasChild
            {
                get { return _hasChild; }
                set { _hasChild = value; }
            }
        }

        private StringBuilder _sb;
        private Stack<Frame> _stack;
        public PartXmlWriter()
            : this(new StringBuilder())
        {
        }
        public PartXmlWriter(StringBuilder sb)
        {
            _sb = sb;
            _stack = new Stack<Frame>();
        }

        private void Write(char c)
        {
            _sb.Append(c);
        }
        private void Write(string s)
        {
            _sb.Append(s);
        }

        public void BeginElem(string tag)
        {
            if (_stack.Any())
            {
                if (!_stack.Peek().HasChild)
                {
                    Write('>');
                    _stack.Peek().HasChild = true;
                }
            }
            Write('<');
            Write(tag);
            _stack.Push(new Frame(tag));
        }
        public void EndElem()
        {
            if (!_stack.Any())
            {
                throw new InvalidOperationException();
            }
            Frame top = _stack.Pop();
            if (top.HasChild)
            {
                Write("</");
                Write(top.Tag);
                Write('>');
            }
            else
            {
                Write(" />");
            }
        }
        public void AddAttr(string key, string val)
        {
            if (_stack.Any() && _stack.Peek().HasChild)
            {
                throw new InvalidOperationException();
            }
            Write(' ');
            Write(key);
            Write("=\"");
            Write(val);
            Write('"');
        }

        public string Text
        {
            get { return _sb.ToString(); }
        }
    }
}
