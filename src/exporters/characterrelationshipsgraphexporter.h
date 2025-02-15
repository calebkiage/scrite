/****************************************************************************
**
** Copyright (C) VCreate Logic Pvt. Ltd. Bengaluru
** Author: Prashanth N Udupa (prashanth@scrite.io)
**
** This code is distributed under GPL v3. Complete text of the license
** can be found here: https://www.gnu.org/licenses/gpl-3.0.txt
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef CHARACTERRELATIONSHIPSGRAPHEXPORTER_H
#define CHARACTERRELATIONSHIPSGRAPHEXPORTER_H

#include "abstractexporter.h"

class CharacterRelationshipGraph;

class CharacterRelationshipsGraphExporter : public AbstractExporter
{
    Q_OBJECT
    Q_CLASSINFO("Format", "Notebook/Character Relationship Graph")
    Q_CLASSINFO("NameFilters", "Adobe PDF (*.pdf)")

public:
    explicit CharacterRelationshipsGraphExporter(QObject *parent = nullptr);
    ~CharacterRelationshipsGraphExporter();

    void setGraph(CharacterRelationshipGraph *val);
    CharacterRelationshipGraph *graph() const { return m_graph; }

    virtual bool requiresConfiguration() const { return true; }

    Q_CLASSINFO("enableHeaderFooter_FieldLabel", "Include header & footer in the generated PDF.")
    Q_CLASSINFO("enableHeaderFooter_FieldEditor", "CheckBox")
    Q_PROPERTY(bool enableHeaderFooter READ isEnableHeaderFooter WRITE setEnableHeaderFooter NOTIFY enableHeaderFooterChanged)
    void setEnableHeaderFooter(bool val);
    bool isEnableHeaderFooter() const { return m_enableHeaderFooter; }
    Q_SIGNAL void enableHeaderFooterChanged();

    Q_CLASSINFO("watermark_FieldLabel", "Watermark text, if enabled.")
    Q_CLASSINFO("watermark_FieldEditor", "TextBox")
    Q_PROPERTY(QString watermark READ watermark WRITE setWatermark NOTIFY watermarkChanged)
    void setWatermark(const QString &val);
    QString watermark() const { return m_watermark; }
    Q_SIGNAL void watermarkChanged();

    Q_CLASSINFO("comment_FieldLabel", "Comment text for use in title card.")
    Q_CLASSINFO("comment_FieldEditor", "TextBox")
    Q_PROPERTY(QString comment READ comment WRITE setComment NOTIFY commentChanged)
    void setComment(const QString &val);
    QString comment() const { return m_comment; }
    Q_SIGNAL void commentChanged();

protected:
    bool doExport(QIODevice *device); // AbstractExporter interface
    QString polishFileName(const QString &fileName) const; // AbstractDeviceIO interface

private:
    bool m_enableHeaderFooter = true;
    QString m_comment;
    QString m_watermark;
    CharacterRelationshipGraph *m_graph = nullptr;
};

#endif // CHARACTERRELATIONSHIPSGRAPHEXPORTER_H
