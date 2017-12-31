/*
 * This file is part of GLShaderDev.
 *
 * GLShaderDev is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GLShaderDev is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GLShaderDev.  If not, see <http://www.gnu.org/licenses/>
 */
#if 0
#ifndef QSCILEXERGLSL_H
#define QSCILEXERGLSL_H

#include <Qsci/qscistyle.h>
#include <Qsci/qscilexercustom.h>

class QsciLexerGLSL : public QsciLexerCustom
{
  Q_OBJECT
public:
  QsciLexerGLSL(QObject *parent = 0);
  ~QsciLexerGLSL();

public:
  const char*	language() const;
  QStringList	autoCompletionWordSeparators() const;
  const char*	blockStartKeyword(int *style = 0) const;
  const char*	blockStart(int *style = 0) const;
  const char*	blockEnd(int *style = 0) const;
  int		braceStyle() const;
  void		styleText(int start, int end);
  QString	description(int style) const;
  QFont		defaultFont(int style) const;
  QColor	defaultColor(int style) const;
  QColor	defaultPaper(int style) const;
  bool		defaultEolFill(int style) const;
  const char*	keywords(int set) const;
  const char*	wordCharacters() const;

private:
  QsciLexerGLSL(const QsciLexerGLSL& other);
  QsciLexerGLSL& operator=(const QsciLexerGLSL& other);

  void	styleLine(const QString& line, int size);

private:
  enum StyleType {
    Default = 0,
    Comment,
    Keyword,
    Operator,
    Macro,
    MaxStyle
  };

private:
  std::map<int, QsciStyle>	_styles;
  QFont				_defaultFont;
};

#endif // SHADERLEXER_H
#endif
